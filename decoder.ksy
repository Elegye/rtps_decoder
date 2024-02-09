meta:
  id: full_decoder
  imports:
    - kaitai_struct_formats/network/pcap
    - kaitai_struct_formats/network/ipv4_packet
    - kaitai_struct_formats/network/udp_datagram
  endian: le
doc: |
  PCAP (named after libpcap / winpcap) is a popular format for saving
  network traffic grabbed by network sniffers. It is typically
  produced by tools like [tcpdump](https://www.tcpdump.org/) or
  [Wireshark](https://www.wireshark.org/).
doc-ref: https://wiki.wireshark.org/Development/LibpcapFileFormat
seq:
  - id: raw
    type: pcap
  - id: ip
    type: ipv4_packet
  - id: packet
    type: udp_datagram