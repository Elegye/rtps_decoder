# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import Enum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Rtps(KaitaiStruct):
    """The RTPS protocol provides DDS interroperability wire protocol.
    """

    class SubmessageId(Enum):
        pad = 1
        acknack = 6
        heartbeat = 7
        gap = 8
        info_ts = 9
        info_src = 12
        info_reply_ip4 = 13
        info_dst = 14
        info_reply = 15
        nack_frag = 18
        heartbeat_frag = 19
        data = 21
        data_frag = 22
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.header = Rtps.RtpsHeader(self._io, self, self._root)
        self.submessage = []
        i = 0
        while not self._io.is_eof():
            self.submessage.append(Rtps.RtpsSubmessage(self._io, self, self._root))
            i += 1


    class InfoSource(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.unused = self._io.read_u4le()
            self.protocol_version = Rtps.ProtocolVersion(self._io, self, self._root)
            self.vendor_id = Rtps.VendorId(self._io, self, self._root)


    class Count(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.value = self._io.read_s4le()


    class FragmentNumber(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.value = self._io.read_u4le()


    class Timestamp(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.seconds = self._io.read_u4le()
            self.fraction = self._io.read_u4le()


    class NackFrag(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_sn = Rtps.SequenceNumber(self._io, self, self._root)
            self.fragment_number_set = Rtps.FragmentNumberSet(self._io, self, self._root)
            self.count = Rtps.Count(self._io, self, self._root)


    class VendorId(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.value = self._io.read_bytes(2)


    class FragmentNumberSet(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.bitmap_base = Rtps.FragmentNumber(self._io, self, self._root)
            self.numbits = self._io.read_u4le()
            self._raw_bitmap = self._io.read_bytes(self.numbits)
            _io__raw_bitmap = KaitaiStream(BytesIO(self._raw_bitmap))
            self.bitmap = Rtps.FragmentNumber(_io__raw_bitmap, self, self._root)


    class Data(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            _on = (self._parent.header.flags & 1)
            if _on == False:
                self._is_le = False
            elif _on == True:
                self._is_le = True
            if not hasattr(self, '_is_le'):
                raise kaitaistruct.UndecidedEndiannessError("/types/data")
            elif self._is_le == True:
                self._read_le()
            elif self._is_le == False:
                self._read_be()

        def _read_le(self):
            self.extra_flags = self._io.read_s2le()
            self.octets_to_inline_qos = self._io.read_u2le()
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_sn = Rtps.SequenceNumber(self._io, self, self._root)
            if (self._parent.header.flags & 2) == 0:
                self.inline_qos = Rtps.ParameterList(self._io, self, self._root)

            if  (((self._parent.header.flags & 4) == 0) or ((self._parent.header.flags & 8) == 0)) :
                self.serialized_payload = Rtps.SerializedPayload(self._io, self, self._root)


        def _read_be(self):
            self.extra_flags = self._io.read_s2be()
            self.octets_to_inline_qos = self._io.read_u2be()
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_sn = Rtps.SequenceNumber(self._io, self, self._root)
            if (self._parent.header.flags & 2) == 0:
                self.inline_qos = Rtps.ParameterList(self._io, self, self._root)

            if  (((self._parent.header.flags & 4) == 0) or ((self._parent.header.flags & 8) == 0)) :
                self.serialized_payload = Rtps.SerializedPayload(self._io, self, self._root)



    class InfoReply(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.unicast_locator_list = Rtps.LocatorList(self._io, self, self._root)
            if (self._parent.header.flags & 2) == 1:
                self.multicast_locator_list = Rtps.LocatorList(self._io, self, self._root)



    class BitmapT(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.value = self._io.read_s4le()


    class SerializedPayloadHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.representation_identifier = self._io.read_s2le()
            self.representation_options = self._io.read_s2le()


    class ParameterId(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.id = self._io.read_s2le()


    class Pad(KaitaiStruct):
        """Pad is leaved blank, as specified by 9.4.5.12."""
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class InfoTimestamp(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.timestamp = Rtps.Timestamp(self._io, self, self._root)


    class SerializedPayload(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Rtps.SerializedPayloadHeader(self._io, self, self._root)
            self.payload = self._io.read_bytes((self._parent._parent.header.octets_to_next_header - 28))


    class GuidPrefix(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.host_id = self._io.read_bytes(4)
            self.app_id = self._io.read_bytes(4)
            self.instance_id = self._io.read_bytes(4)


    class EntityId(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.key = self._io.read_bytes(3)
            self.kind = self._io.read_bytes(1)


    class Acknack(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.reader_sn_state = Rtps.SequenceNumberSet(self._io, self, self._root)
            self.count = Rtps.Count(self._io, self, self._root)


    class LocatorList(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.value = Rtps.Locator(self._io, self, self._root)


    class Gap(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.gap_start = Rtps.SequenceNumber(self._io, self, self._root)
            self.gap_list = Rtps.SequenceNumberSet(self._io, self, self._root)


    class InfoDestination(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.guid_prefix = Rtps.GuidPrefix(self._io, self, self._root)


    class RtpsSubmessage(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Rtps.SubmessageHeader(self._io, self, self._root)
            _on = self.header.submessage_id
            if _on == Rtps.SubmessageId.info_src:
                self.payload = Rtps.InfoSource(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.acknack:
                self.payload = Rtps.Acknack(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.info_ts:
                self.payload = Rtps.InfoTimestamp(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.info_reply:
                self.payload = Rtps.InfoReply(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.gap:
                self.payload = Rtps.Gap(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.pad:
                self.payload = Rtps.Pad(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.info_dst:
                self.payload = Rtps.InfoDestination(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.data:
                self.payload = Rtps.Data(self._io, self, self._root)
            elif _on == Rtps.SubmessageId.heartbeat:
                self.payload = Rtps.Heartbeat(self._io, self, self._root)


    class AppId(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.instance_id = self._io.read_bytes(3)
            self.app_kind = self._io.read_bytes(1)


    class SubmessageHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.submessage_id = KaitaiStream.resolve_enum(Rtps.SubmessageId, self._io.read_s1())
            self.flags = self._io.read_u1()
            self.octets_to_next_header = self._io.read_u2le()


    class Locator(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.kind = self._io.read_s4le()
            self.port = self._io.read_u4le()
            self.address = self._io.read_bytes(16)


    class SequenceNumber(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.high = self._io.read_bytes(4)
            self.low = self._io.read_bytes(4)


    class RtpsHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(4)
            if not self.magic == b"\x52\x54\x50\x53":
                raise kaitaistruct.ValidationNotEqualError(b"\x52\x54\x50\x53", self.magic, self._io, u"/types/rtps_header/seq/0")
            self.protocol_version = Rtps.ProtocolVersion(self._io, self, self._root)
            self.vendor_id = Rtps.VendorId(self._io, self, self._root)
            self.guid_prefix = Rtps.GuidPrefix(self._io, self, self._root)


    class ParameterList(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.parameter_id = Rtps.ParameterId(self._io, self, self._root)
            self.length = self._io.read_s2le()
            self.value = self._io.read_bytes(self.length)


    class ProtocolVersion(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.major = self._io.read_u1()
            self.minor = self._io.read_u1()


    class SequenceNumberSet(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.bitmap_base = Rtps.SequenceNumber(self._io, self, self._root)
            self.numbits = self._io.read_u4le()
            self.bitmap = []
            for i in range((self.numbits + 31) // 32):
                self.bitmap.append(Rtps.BitmapT(self._io, self, self._root))



    class Heartbeat(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.reader_id = Rtps.EntityId(self._io, self, self._root)
            self.writer_id = Rtps.EntityId(self._io, self, self._root)
            self.first_sn = Rtps.SequenceNumber(self._io, self, self._root)
            self.last_sn = Rtps.SequenceNumber(self._io, self, self._root)
            self.count = Rtps.Count(self._io, self, self._root)



