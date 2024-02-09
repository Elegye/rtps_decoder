import build.pcap as pcap
import loopback
import rtps

pcap_file = pcap.Pcap.from_file("./data/vehicle_rtps.pcap")

packet: pcap.Pcap.Packet
subm: rtps.Rtps.RtpsSubmessage

for packet in pcap_file.packets:
    lo = loopback.Loopback.from_bytes((packet.body))
    print((lo.ip.body.body.dst_port))
    real = rtps.Rtps.from_bytes(lo.ip.body.body.body)

    for subm in real.submessage:
        print(subm.header.submessage_id)
        print("\n", subm.payload.__dict__)
    