import build.pcap as pcap
import loopback
import rtps

pcap_file = pcap.Pcap.from_file("./data/vehicle_rtps.pcap")

packet: pcap.Pcap.Packet
subm: rtps.Rtps.RtpsSubmessage

participants = {}

for packet in pcap_file.packets:
    lo = loopback.Loopback.from_bytes((packet.body))
    real = rtps.Rtps.from_bytes(lo.ip.body.body.body)

    for subm in real.submessage:
        id = subm.header.submessage_id
        if id == rtps.Rtps.SubmessageId.data:
            print(subm.payload)
        elif id == rtps.Rtps.SubmessageId.heartbeat:
            print(subm.payload.__dict__)
        elif id == rtps.Rtps.SubmessageId.info_dst:
            print(subm.payload.__dict__)
        elif id == rtps.Rtps.SubmessageId.info_src:
            print(subm.payload.__dict__)
        elif id == rtps.Rtps.SubmessageId.info_ts:
            print(subm.payload.__dict__)
        elif id == rtps.Rtps.SubmessageId.acknack:
            print(subm.payload.__dict__)