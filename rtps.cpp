// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "rtps.h"
#include "kaitai/exceptions.h"

rtps_t::rtps_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_header = 0;
    m_submessage = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::_read() {
    m_header = new rtps_header_t(m__io, this, m__root);
    m_submessage = new std::vector<rtps_submessage_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_submessage->push_back(new rtps_submessage_t(m__io, this, m__root));
            i++;
        }
    }
}

rtps_t::~rtps_t() {
    _clean_up();
}

void rtps_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_submessage) {
        for (std::vector<rtps_submessage_t*>::iterator it = m_submessage->begin(); it != m_submessage->end(); ++it) {
            delete *it;
        }
        delete m_submessage; m_submessage = 0;
    }
}

rtps_t::info_source_t::info_source_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_protocol_version = 0;
    m_vendor_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::info_source_t::_read() {
    m_unused = m__io->read_u4le();
    m_protocol_version = new protocol_version_t(m__io, this, m__root);
    m_vendor_id = new vendor_id_t(m__io, this, m__root);
}

rtps_t::info_source_t::~info_source_t() {
    _clean_up();
}

void rtps_t::info_source_t::_clean_up() {
    if (m_protocol_version) {
        delete m_protocol_version; m_protocol_version = 0;
    }
    if (m_vendor_id) {
        delete m_vendor_id; m_vendor_id = 0;
    }
}

rtps_t::count_t::count_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::count_t::_read() {
    m_value = m__io->read_u4le();
}

rtps_t::count_t::~count_t() {
    _clean_up();
}

void rtps_t::count_t::_clean_up() {
}

rtps_t::fragment_number_t::fragment_number_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::fragment_number_t::_read() {
    m_value = m__io->read_u4le();
}

rtps_t::fragment_number_t::~fragment_number_t() {
    _clean_up();
}

void rtps_t::fragment_number_t::_clean_up() {
}

rtps_t::timestamp_t::timestamp_t(kaitai::kstream* p__io, rtps_t::info_timestamp_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::timestamp_t::_read() {
    m_seconds = m__io->read_u4le();
    m_fraction = m__io->read_u4le();
}

rtps_t::timestamp_t::~timestamp_t() {
    _clean_up();
}

void rtps_t::timestamp_t::_clean_up() {
}

rtps_t::nack_frag_t::nack_frag_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reader_id = 0;
    m_writer_id = 0;
    m_writer_sn = 0;
    m_fragment_number_set = 0;
    m_count = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::nack_frag_t::_read() {
    m_reader_id = new entity_id_t(m__io, this, m__root);
    m_writer_id = new entity_id_t(m__io, this, m__root);
    m_writer_sn = new sequence_number_t(m__io, this, m__root);
    m_fragment_number_set = new fragment_number_set_t(m__io, this, m__root);
    m_count = new count_t(m__io, this, m__root);
}

rtps_t::nack_frag_t::~nack_frag_t() {
    _clean_up();
}

void rtps_t::nack_frag_t::_clean_up() {
    if (m_reader_id) {
        delete m_reader_id; m_reader_id = 0;
    }
    if (m_writer_id) {
        delete m_writer_id; m_writer_id = 0;
    }
    if (m_writer_sn) {
        delete m_writer_sn; m_writer_sn = 0;
    }
    if (m_fragment_number_set) {
        delete m_fragment_number_set; m_fragment_number_set = 0;
    }
    if (m_count) {
        delete m_count; m_count = 0;
    }
}

rtps_t::vendor_id_t::vendor_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::vendor_id_t::_read() {
    m_value = m__io->read_bytes(2);
}

rtps_t::vendor_id_t::~vendor_id_t() {
    _clean_up();
}

void rtps_t::vendor_id_t::_clean_up() {
}

rtps_t::fragment_number_set_t::fragment_number_set_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bitmap_base = 0;
    m_bitmap = 0;
    m__io__raw_bitmap = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::fragment_number_set_t::_read() {
    m_bitmap_base = new fragment_number_t(m__io, this, m__root);
    m_numbits = m__io->read_u4le();
    m__raw_bitmap = m__io->read_bytes(numbits());
    m__io__raw_bitmap = new kaitai::kstream(m__raw_bitmap);
    m_bitmap = new fragment_number_t(m__io__raw_bitmap, this, m__root);
}

rtps_t::fragment_number_set_t::~fragment_number_set_t() {
    _clean_up();
}

void rtps_t::fragment_number_set_t::_clean_up() {
    if (m_bitmap_base) {
        delete m_bitmap_base; m_bitmap_base = 0;
    }
    if (m__io__raw_bitmap) {
        delete m__io__raw_bitmap; m__io__raw_bitmap = 0;
    }
    if (m_bitmap) {
        delete m_bitmap; m_bitmap = 0;
    }
}

rtps_t::data_t::data_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reader_id = 0;
    m_writer_id = 0;
    m_writer_sn = 0;
    m_inline_qos = 0;
    m_serialized_payload = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::data_t::_read() {
    m_extra_flags = m__io->read_s2le();
    m_octets_to_inline_qos = m__io->read_u2le();
    m_reader_id = new entity_id_t(m__io, this, m__root);
    m_writer_id = new entity_id_t(m__io, this, m__root);
    m_writer_sn = new sequence_number_t(m__io, this, m__root);
    n_inline_qos = true;
    if ((_parent()->header()->flags() & 2) == 0) {
        n_inline_qos = false;
        m_inline_qos = new parameter_list_t(m__io, this, m__root);
    }
    n_serialized_payload = true;
    if ( (((_parent()->header()->flags() & 4) == 0) || ((_parent()->header()->flags() & 8) == 0)) ) {
        n_serialized_payload = false;
        m_serialized_payload = new serialized_payload_t(m__io, this, m__root);
    }
}

rtps_t::data_t::~data_t() {
    _clean_up();
}

void rtps_t::data_t::_clean_up() {
    if (m_reader_id) {
        delete m_reader_id; m_reader_id = 0;
    }
    if (m_writer_id) {
        delete m_writer_id; m_writer_id = 0;
    }
    if (m_writer_sn) {
        delete m_writer_sn; m_writer_sn = 0;
    }
    if (!n_inline_qos) {
        if (m_inline_qos) {
            delete m_inline_qos; m_inline_qos = 0;
        }
    }
    if (!n_serialized_payload) {
        if (m_serialized_payload) {
            delete m_serialized_payload; m_serialized_payload = 0;
        }
    }
}

rtps_t::info_reply_t::info_reply_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_unicast_locator_list = 0;
    m_multicast_locator_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::info_reply_t::_read() {
    m_unicast_locator_list = new locator_list_t(m__io, this, m__root);
    n_multicast_locator_list = true;
    if ((_parent()->header()->flags() & 2) == 1) {
        n_multicast_locator_list = false;
        m_multicast_locator_list = new locator_list_t(m__io, this, m__root);
    }
}

rtps_t::info_reply_t::~info_reply_t() {
    _clean_up();
}

void rtps_t::info_reply_t::_clean_up() {
    if (m_unicast_locator_list) {
        delete m_unicast_locator_list; m_unicast_locator_list = 0;
    }
    if (!n_multicast_locator_list) {
        if (m_multicast_locator_list) {
            delete m_multicast_locator_list; m_multicast_locator_list = 0;
        }
    }
}

rtps_t::bitmap_t_t::bitmap_t_t(kaitai::kstream* p__io, rtps_t::sequence_number_set_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::bitmap_t_t::_read() {
    m_value = m__io->read_s4le();
}

rtps_t::bitmap_t_t::~bitmap_t_t() {
    _clean_up();
}

void rtps_t::bitmap_t_t::_clean_up() {
}

rtps_t::serialized_payload_header_t::serialized_payload_header_t(kaitai::kstream* p__io, rtps_t::serialized_payload_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::serialized_payload_header_t::_read() {
    m_representation_identifier = m__io->read_u2le();
    m_representation_options = m__io->read_u2le();
}

rtps_t::serialized_payload_header_t::~serialized_payload_header_t() {
    _clean_up();
}

void rtps_t::serialized_payload_header_t::_clean_up() {
}

rtps_t::parameter_id_t::parameter_id_t(kaitai::kstream* p__io, rtps_t::parameter_list_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::parameter_id_t::_read() {
    m_id = m__io->read_s2le();
}

rtps_t::parameter_id_t::~parameter_id_t() {
    _clean_up();
}

void rtps_t::parameter_id_t::_clean_up() {
}

rtps_t::pad_t::pad_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::pad_t::_read() {
}

rtps_t::pad_t::~pad_t() {
    _clean_up();
}

void rtps_t::pad_t::_clean_up() {
}

rtps_t::info_timestamp_t::info_timestamp_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_timestamp = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::info_timestamp_t::_read() {
    m_timestamp = new timestamp_t(m__io, this, m__root);
}

rtps_t::info_timestamp_t::~info_timestamp_t() {
    _clean_up();
}

void rtps_t::info_timestamp_t::_clean_up() {
    if (m_timestamp) {
        delete m_timestamp; m_timestamp = 0;
    }
}

rtps_t::serialized_payload_t::serialized_payload_t(kaitai::kstream* p__io, rtps_t::data_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::serialized_payload_t::_read() {
    m_header = new serialized_payload_header_t(m__io, this, m__root);
    m_payload = m__io->read_bytes((_parent()->_parent()->header()->octets_to_next_header() - 28));
}

rtps_t::serialized_payload_t::~serialized_payload_t() {
    _clean_up();
}

void rtps_t::serialized_payload_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
}

rtps_t::guid_prefix_t::guid_prefix_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::guid_prefix_t::_read() {
    m_host_id = m__io->read_u4be();
    m_app_id = m__io->read_u4be();
    m_instance_id = m__io->read_u4be();
}

rtps_t::guid_prefix_t::~guid_prefix_t() {
    _clean_up();
}

void rtps_t::guid_prefix_t::_clean_up() {
}

rtps_t::entity_id_t::entity_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_raw_key = false;
    f_raw_kind = false;
    f_kind = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::entity_id_t::_read() {
    m_value = m__io->read_u4be();
}

rtps_t::entity_id_t::~entity_id_t() {
    _clean_up();
}

void rtps_t::entity_id_t::_clean_up() {
}

int32_t rtps_t::entity_id_t::raw_key() {
    if (f_raw_key)
        return m_raw_key;
    m_raw_key = (value() >> (16 - 8));
    f_raw_key = true;
    return m_raw_key;
}

int32_t rtps_t::entity_id_t::raw_kind() {
    if (f_raw_kind)
        return m_raw_kind;
    m_raw_kind = ((value() >> (8 * 16)) & 255);
    f_raw_kind = true;
    return m_raw_kind;
}

rtps_t::entity_kind_t rtps_t::entity_id_t::kind() {
    if (f_kind)
        return m_kind;
    m_kind = static_cast<rtps_t::entity_kind_t>(value());
    f_kind = true;
    return m_kind;
}

rtps_t::acknack_t::acknack_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reader_id = 0;
    m_writer_id = 0;
    m_reader_sn_state = 0;
    m_count = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::acknack_t::_read() {
    m_reader_id = new entity_id_t(m__io, this, m__root);
    m_writer_id = new entity_id_t(m__io, this, m__root);
    m_reader_sn_state = new sequence_number_set_t(m__io, this, m__root);
    m_count = new count_t(m__io, this, m__root);
}

rtps_t::acknack_t::~acknack_t() {
    _clean_up();
}

void rtps_t::acknack_t::_clean_up() {
    if (m_reader_id) {
        delete m_reader_id; m_reader_id = 0;
    }
    if (m_writer_id) {
        delete m_writer_id; m_writer_id = 0;
    }
    if (m_reader_sn_state) {
        delete m_reader_sn_state; m_reader_sn_state = 0;
    }
    if (m_count) {
        delete m_count; m_count = 0;
    }
}

rtps_t::locator_list_t::locator_list_t(kaitai::kstream* p__io, rtps_t::info_reply_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_value = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::locator_list_t::_read() {
    m_value = new locator_t(m__io, this, m__root);
}

rtps_t::locator_list_t::~locator_list_t() {
    _clean_up();
}

void rtps_t::locator_list_t::_clean_up() {
    if (m_value) {
        delete m_value; m_value = 0;
    }
}

rtps_t::gap_t::gap_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reader_id = 0;
    m_writer_id = 0;
    m_gap_start = 0;
    m_gap_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::gap_t::_read() {
    m_reader_id = new entity_id_t(m__io, this, m__root);
    m_writer_id = new entity_id_t(m__io, this, m__root);
    m_gap_start = new sequence_number_t(m__io, this, m__root);
    m_gap_list = new sequence_number_set_t(m__io, this, m__root);
}

rtps_t::gap_t::~gap_t() {
    _clean_up();
}

void rtps_t::gap_t::_clean_up() {
    if (m_reader_id) {
        delete m_reader_id; m_reader_id = 0;
    }
    if (m_writer_id) {
        delete m_writer_id; m_writer_id = 0;
    }
    if (m_gap_start) {
        delete m_gap_start; m_gap_start = 0;
    }
    if (m_gap_list) {
        delete m_gap_list; m_gap_list = 0;
    }
}

rtps_t::info_destination_t::info_destination_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_guid_prefix = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::info_destination_t::_read() {
    m_guid_prefix = new guid_prefix_t(m__io, this, m__root);
}

rtps_t::info_destination_t::~info_destination_t() {
    _clean_up();
}

void rtps_t::info_destination_t::_clean_up() {
    if (m_guid_prefix) {
        delete m_guid_prefix; m_guid_prefix = 0;
    }
}

rtps_t::rtps_submessage_t::rtps_submessage_t(kaitai::kstream* p__io, rtps_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::rtps_submessage_t::_read() {
    m_header = new submessage_header_t(m__io, this, m__root);
    n_payload = true;
    switch (header()->submessage_id()) {
    case rtps_t::SUBMESSAGE_ID_INFO_SRC: {
        n_payload = false;
        m_payload = new info_source_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_ACKNACK: {
        n_payload = false;
        m_payload = new acknack_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_INFO_TS: {
        n_payload = false;
        m_payload = new info_timestamp_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_INFO_REPLY: {
        n_payload = false;
        m_payload = new info_reply_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_GAP: {
        n_payload = false;
        m_payload = new gap_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_PAD: {
        n_payload = false;
        m_payload = new pad_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_INFO_DST: {
        n_payload = false;
        m_payload = new info_destination_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_DATA: {
        n_payload = false;
        m_payload = new data_t(m__io, this, m__root);
        break;
    }
    case rtps_t::SUBMESSAGE_ID_HEARTBEAT: {
        n_payload = false;
        m_payload = new heartbeat_t(m__io, this, m__root);
        break;
    }
    }
}

rtps_t::rtps_submessage_t::~rtps_submessage_t() {
    _clean_up();
}

void rtps_t::rtps_submessage_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (!n_payload) {
        if (m_payload) {
            delete m_payload; m_payload = 0;
        }
    }
}

rtps_t::submessage_header_t::submessage_header_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::submessage_header_t::_read() {
    m_submessage_id = static_cast<rtps_t::submessage_id_t>(m__io->read_s1());
    m_flags = m__io->read_u1();
    m_octets_to_next_header = m__io->read_u2le();
}

rtps_t::submessage_header_t::~submessage_header_t() {
    _clean_up();
}

void rtps_t::submessage_header_t::_clean_up() {
}

rtps_t::locator_t::locator_t(kaitai::kstream* p__io, rtps_t::locator_list_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::locator_t::_read() {
    m_kind = m__io->read_s4le();
    m_port = m__io->read_u4le();
    m_address = m__io->read_bytes(16);
}

rtps_t::locator_t::~locator_t() {
    _clean_up();
}

void rtps_t::locator_t::_clean_up() {
}

rtps_t::sequence_number_t::sequence_number_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::sequence_number_t::_read() {
    m_high = m__io->read_u4be();
    m_low = m__io->read_u4be();
}

rtps_t::sequence_number_t::~sequence_number_t() {
    _clean_up();
}

void rtps_t::sequence_number_t::_clean_up() {
}

rtps_t::rtps_header_t::rtps_header_t(kaitai::kstream* p__io, rtps_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_protocol_version = 0;
    m_vendor_id = 0;
    m_guid_prefix = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::rtps_header_t::_read() {
    m_magic = m__io->read_bytes(4);
    if (!(magic() == std::string("\x52\x54\x50\x53", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x52\x54\x50\x53", 4), magic(), _io(), std::string("/types/rtps_header/seq/0"));
    }
    m_protocol_version = new protocol_version_t(m__io, this, m__root);
    m_vendor_id = new vendor_id_t(m__io, this, m__root);
    m_guid_prefix = new guid_prefix_t(m__io, this, m__root);
}

rtps_t::rtps_header_t::~rtps_header_t() {
    _clean_up();
}

void rtps_t::rtps_header_t::_clean_up() {
    if (m_protocol_version) {
        delete m_protocol_version; m_protocol_version = 0;
    }
    if (m_vendor_id) {
        delete m_vendor_id; m_vendor_id = 0;
    }
    if (m_guid_prefix) {
        delete m_guid_prefix; m_guid_prefix = 0;
    }
}

rtps_t::parameter_list_t::parameter_list_t(kaitai::kstream* p__io, rtps_t::data_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_parameter_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::parameter_list_t::_read() {
    m_parameter_id = new parameter_id_t(m__io, this, m__root);
    m_length = m__io->read_s2le();
    m_value = m__io->read_bytes(length());
}

rtps_t::parameter_list_t::~parameter_list_t() {
    _clean_up();
}

void rtps_t::parameter_list_t::_clean_up() {
    if (m_parameter_id) {
        delete m_parameter_id; m_parameter_id = 0;
    }
}

rtps_t::protocol_version_t::protocol_version_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::protocol_version_t::_read() {
    m_major = m__io->read_u1();
    m_minor = m__io->read_u1();
}

rtps_t::protocol_version_t::~protocol_version_t() {
    _clean_up();
}

void rtps_t::protocol_version_t::_clean_up() {
}

rtps_t::sequence_number_set_t::sequence_number_set_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bitmap_base = 0;
    m_bitmap = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::sequence_number_set_t::_read() {
    m_bitmap_base = new sequence_number_t(m__io, this, m__root);
    m_numbits = m__io->read_u4le();
    m_bitmap = new std::vector<bitmap_t_t*>();
    const int l_bitmap = ((numbits() + 31) / 32);
    for (int i = 0; i < l_bitmap; i++) {
        m_bitmap->push_back(new bitmap_t_t(m__io, this, m__root));
    }
}

rtps_t::sequence_number_set_t::~sequence_number_set_t() {
    _clean_up();
}

void rtps_t::sequence_number_set_t::_clean_up() {
    if (m_bitmap_base) {
        delete m_bitmap_base; m_bitmap_base = 0;
    }
    if (m_bitmap) {
        for (std::vector<bitmap_t_t*>::iterator it = m_bitmap->begin(); it != m_bitmap->end(); ++it) {
            delete *it;
        }
        delete m_bitmap; m_bitmap = 0;
    }
}

rtps_t::heartbeat_t::heartbeat_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent, rtps_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reader_id = 0;
    m_writer_id = 0;
    m_first_sn = 0;
    m_last_sn = 0;
    m_count = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void rtps_t::heartbeat_t::_read() {
    m_reader_id = new entity_id_t(m__io, this, m__root);
    m_writer_id = new entity_id_t(m__io, this, m__root);
    m_first_sn = new sequence_number_t(m__io, this, m__root);
    m_last_sn = new sequence_number_t(m__io, this, m__root);
    m_count = new count_t(m__io, this, m__root);
}

rtps_t::heartbeat_t::~heartbeat_t() {
    _clean_up();
}

void rtps_t::heartbeat_t::_clean_up() {
    if (m_reader_id) {
        delete m_reader_id; m_reader_id = 0;
    }
    if (m_writer_id) {
        delete m_writer_id; m_writer_id = 0;
    }
    if (m_first_sn) {
        delete m_first_sn; m_first_sn = 0;
    }
    if (m_last_sn) {
        delete m_last_sn; m_last_sn = 0;
    }
    if (m_count) {
        delete m_count; m_count = 0;
    }
}
