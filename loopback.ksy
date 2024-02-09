meta:
    id: loopback
    title: Loopback
    endian: le
    imports:
      - /network/ipv4_packet
      - /../rtps
seq:
  - id: header
    type: u4
  - id: ip
    type: ipv4_packet