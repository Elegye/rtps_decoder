#include <stdio.h>
#include <pcap.h>
#include <format>

#include <sstream>
#include "rtps.h"
#include "kaitai/kaitaistream.h"

#include <iostream>

/* For information on what filters are available
   use the man page for pcap-filter
   $ man pcap-filter
*/

int main(int argc, char **argv) {

    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;

    handle = pcap_open_offline("data/vehicle_rtps.pcap", error_buffer);
    if (nullptr == handle) {
        printf("Could not open %s\n", error_buffer);
        return 2;
    }

    struct pcap_pkthdr *header;
    const u_char *payload;
    std::string util_payload;
    std::string raw_rtps;
    int i = 0;

    while (pcap_next_ex(handle, &header, &payload) > 0)
    {
        util_payload = std::string(reinterpret_cast<const char*>(payload), static_cast<size_t>(header->caplen));
        // We do not want header like loopback and UDP
        raw_rtps = util_payload.substr(32, util_payload.size());
        std::cout << i++ << "-" << header->ts.tv_sec << " Length: " << header->caplen << std::endl;
        std::cout << raw_rtps.size() << std::endl;

        std::istringstream is(raw_rtps);
        kaitai::kstream ks(&is);
        rtps_t packet(&ks);

        std::cout << "\t" << std::hex << packet.header()->guid_prefix()->host_id() << std::endl;
        std::cout << "\t" << std::hex << packet.header()->guid_prefix()->app_id() << std::endl;
        std::cout << "\t" << std::hex << packet.header()->guid_prefix()->instance_id() << std::endl;

        std::cout << "\t" << std::endl;
        
        std::cout << "\t" << "Submessages: " << packet.submessage()->size() << std::endl;
        for(auto const& subm: *packet.submessage())
        {
            switch (subm->header()->submessage_id())
            {
            case rtps_t::submessage_id_t::SUBMESSAGE_ID_DATA:
            {
                auto data = reinterpret_cast<rtps_t::data_t*>(subm->payload());
                std::cout << "\t\t" << "DATA Payload: " << std::endl;
                std::cout << "\t\t\t" << "Writer Raw Value: " << std::hex << data->writer_id()->value() << std::endl;
                std::cout << "\t\t\t" << "Writer Key: " << std::hex << data->writer_id()->raw_key() << std::endl;
                std::cout << "\t\t\t" << "Writer Kind: " << std::hex << data->writer_id()->raw_kind() << std::endl;
                std::cout << "\t\t\t" << "Writer Human Kind: " << data->writer_id()->kind() << std::endl;
                std::cout << "\t\t\t" << "Writer Sn: " << std::hex << data->writer_sn()->low() << std::endl;
                std::cout << "\t\t\t" << "Writer Data: " << std::hex << data->serialized_payload()->payload() << std::endl;

            }   
                break;
            case rtps_t::submessage_id_t::SUBMESSAGE_ID_INFO_TS:
            {
                auto info_ts = reinterpret_cast<rtps_t::info_timestamp_t*>(subm->payload());
                std::cout << "\t\t" << "INFO_TS Payload: " << std::dec << std::endl;
                std::cout << "\t\t\t" << "Timestamp: " << info_ts->timestamp()->seconds() << std::endl;
            }
                break;
            case rtps_t::submessage_id_t::SUBMESSAGE_ID_ACKNACK:
            {
                auto acknack = reinterpret_cast<rtps_t::acknack_t*>(subm->payload());
                std::cout << "\t\t" << "ACKNACK Payload: " << std::dec << std::endl;
                std::cout << "\t\t\t" << "Writer Id kind: " << acknack->writer_id()->kind() << std::endl;
                std::cout << "\t\t\t" << "SequenceNumber: " << std::endl;
                for(auto const num: *acknack->reader_sn_state()->bitmap())
                {
                    std::cout << "\t\t\t\t" << "Seq: " << std::dec << num->value() << std::endl;
                }
                std::cout << "\t\t\t" << "Count: " << std::dec << acknack->count() << std::endl;
            }
                break;
            case rtps_t::submessage_id_t::SUBMESSAGE_ID_HEARTBEAT:
            {
                auto heartbeat = reinterpret_cast<rtps_t::heartbeat_t*>(subm->payload());
                std::cout << "\t\t" << "HEARTBEAT Payload: " << std::dec << std::endl;
                std::cout << "\t\t\t" << "Writer Id kind: " << heartbeat->writer_id()->kind() << std::endl;
                std::cout << "\t\t\t" << "FirstSn: " << heartbeat->first_sn()->high() << "-" << heartbeat->first_sn()->high() << std::endl;
                std::cout << "\t\t\t" << "Count: " << std::dec << heartbeat->count() << std::endl;
            }
                break;
            default:
                break;
            }            
        }
        
        std::cout << std::dec;
    }
    
    return 0;
}