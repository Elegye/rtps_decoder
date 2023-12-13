from kaitaistruct import KaitaiStream, BytesIO
import datetime
import rtps

# data = rtps.Rtps.from_file("data/info_src.bin")

# print(data.header.protocol_version.major)
# print(data.header.protocol_version.minor)
# print(data.header.vendor_id.value[0])
# print(data.header.vendor_id.value[1])
# print(data.header.guid_prefix.host_id)
# print(data.header.guid_prefix.app_id.instance_id)
# print(data.header.guid_prefix.app_id.app_kind)

# print(data.submessage.header.submessage_id)
# print(int(data.submessage.header.flags))
# print(int(data.submessage.header.octets_to_next_header))
# print((data.submessage.payload.protocol_version.major))
# print((data.submessage.payload.protocol_version.minor))

# data = rtps.Rtps.from_file("data/info_ts.bin")

# print(data.header.protocol_version.major)
# print(data.header.protocol_version.minor)
# print(data.header.vendor_id.value[0])
# print(data.header.vendor_id.value[1])
# print(data.header.guid_prefix.host_id)
# print(data.header.guid_prefix.app_id.instance_id)
# print(data.header.guid_prefix.app_id.app_kind)

# print(data.submessage.header.submessage_id)
# print((data.submessage.header.flags))
# print((data.submessage.header.octets_to_next_header))

# print(data.submessage.payload.timestamp.seconds)

data = rtps.Rtps.from_file("data/info_ts_data.bin")

print(f"Protocol Version: {data.header.protocol_version.major}.{data.header.protocol_version.minor}")
print(f"Vendor ID: {data.header.vendor_id.value[0]} - {data.header.vendor_id.value[1]}")
print(f"Host ID: {bytes(data.header.guid_prefix.host_id).hex()}")
print(f"App ID: {bytes(data.header.guid_prefix.app_id).hex()}")
print(f"Instance ID: {bytes(data.header.guid_prefix.instance_id).hex()}")

for submessage in data.submessage:
    print(f"ID: {submessage.header.submessage_id}")
    print(f"Flags: {submessage.header.flags}")
    print(f"octets_to_next_header: {submessage.header.octets_to_next_header}")

    if submessage.header.submessage_id == rtps.Rtps.SubmessageId.info_ts:
        timestamp = submessage.payload.timestamp.seconds + (submessage.payload.timestamp.fraction / 2**32)
        print(f"timestamp: {datetime.datetime.fromtimestamp(timestamp)}")
        print(f"timestamp seconds: {submessage.payload.timestamp.seconds}")
        print(f"timestamp fraction: {submessage.payload.timestamp.fraction}")
    elif submessage.header.submessage_id == rtps.Rtps.SubmessageId.info_src:
        print(f"Protocol Version: {submessage.payload.protocol_version.major}.{submessage.payload.protocol_version.minor}")
    elif submessage.header.submessage_id == rtps.Rtps.SubmessageId.data:
        print(f"ReaderId: {submessage.payload.reader_id.key}, kind {submessage.payload.reader_id.kind}")
        print(f"WriterId: {submessage.payload.writer_id.key}, kind {submessage.payload.writer_id.kind}")
        print(f"WriterSequenceNumber: ({submessage.payload.writer_sn.high}, {submessage.payload.writer_sn.low})")
        print(f"WriterSequenceNumber: ({submessage.payload.writer_sn.high}, {submessage.payload.writer_sn.low})")
        print(f"SerialiazedPayload: ({submessage.payload.serialized_payload.payload})")


