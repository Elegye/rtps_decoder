#ifndef RTPS_H_
#define RTPS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * The RTPS protocol provides DDS interroperability wire protocol.
 */

class rtps_t : public kaitai::kstruct {

public:
    class info_source_t;
    class count_t;
    class fragment_number_t;
    class timestamp_t;
    class nack_frag_t;
    class vendor_id_t;
    class fragment_number_set_t;
    class data_t;
    class info_reply_t;
    class bitmap_t_t;
    class serialized_payload_header_t;
    class parameter_id_t;
    class pad_t;
    class info_timestamp_t;
    class serialized_payload_t;
    class guid_prefix_t;
    class entity_id_t;
    class acknack_t;
    class locator_list_t;
    class gap_t;
    class info_destination_t;
    class rtps_submessage_t;
    class submessage_header_t;
    class locator_t;
    class sequence_number_t;
    class rtps_header_t;
    class parameter_list_t;
    class protocol_version_t;
    class sequence_number_set_t;
    class heartbeat_t;

    enum submessage_id_t {
        SUBMESSAGE_ID_PAD = 1,
        SUBMESSAGE_ID_ACKNACK = 6,
        SUBMESSAGE_ID_HEARTBEAT = 7,
        SUBMESSAGE_ID_GAP = 8,
        SUBMESSAGE_ID_INFO_TS = 9,
        SUBMESSAGE_ID_INFO_SRC = 12,
        SUBMESSAGE_ID_INFO_REPLY_IP4 = 13,
        SUBMESSAGE_ID_INFO_DST = 14,
        SUBMESSAGE_ID_INFO_REPLY = 15,
        SUBMESSAGE_ID_NACK_FRAG = 18,
        SUBMESSAGE_ID_HEARTBEAT_FRAG = 19,
        SUBMESSAGE_ID_DATA = 21,
        SUBMESSAGE_ID_DATA_FRAG = 22
    };

    enum entity_kind_t {
        ENTITY_KIND_ENTITYID_UNKNOWN = 0,
        ENTITY_KIND_ENTITYID_PARTICIPANT = 449,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_TOPICS_ANNOUNCER = 706,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_TOPICS_DETECTOR = 711,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_PUBLICATIONS_ANNOUNCER = 962,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_PUBLICATIONS_DETECTOR = 967,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_SUBSCRIPTIONS_ANNOUNCER = 1218,
        ENTITY_KIND_ENTITYID_SEDP_BUILTIN_SUBSCRIPTIONS_DETECTOR = 1223,
        ENTITY_KIND_ENTITYID_SPDP_BUILTIN_PARTICIPANT_ANNOUNCER = 65730,
        ENTITY_KIND_ENTITYID_SPDP_BUILTIN_PARTICIPANT_DETECTOR = 65735,
        ENTITY_KIND_ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER = 131266,
        ENTITY_KIND_ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_READER = 131271
    };

    rtps_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~rtps_t();

    class info_source_t : public kaitai::kstruct {

    public:

        info_source_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~info_source_t();

    private:
        uint32_t m_unused;
        protocol_version_t* m_protocol_version;
        vendor_id_t* m_vendor_id;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        uint32_t unused() const { return m_unused; }
        protocol_version_t* protocol_version() const { return m_protocol_version; }
        vendor_id_t* vendor_id() const { return m_vendor_id; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class count_t : public kaitai::kstruct {

    public:

        count_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~count_t();

    private:
        uint32_t m_value;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class fragment_number_t : public kaitai::kstruct {

    public:

        fragment_number_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~fragment_number_t();

    private:
        uint32_t m_value;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class timestamp_t : public kaitai::kstruct {

    public:

        timestamp_t(kaitai::kstream* p__io, rtps_t::info_timestamp_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~timestamp_t();

    private:
        uint32_t m_seconds;
        uint32_t m_fraction;
        rtps_t* m__root;
        rtps_t::info_timestamp_t* m__parent;

    public:

        /**
         * Time in seconds
         */
        uint32_t seconds() const { return m_seconds; }

        /**
         * Time in sec/2^32
         */
        uint32_t fraction() const { return m_fraction; }
        rtps_t* _root() const { return m__root; }
        rtps_t::info_timestamp_t* _parent() const { return m__parent; }
    };

    class nack_frag_t : public kaitai::kstruct {

    public:

        nack_frag_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~nack_frag_t();

    private:
        entity_id_t* m_reader_id;
        entity_id_t* m_writer_id;
        sequence_number_t* m_writer_sn;
        fragment_number_set_t* m_fragment_number_set;
        count_t* m_count;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        entity_id_t* reader_id() const { return m_reader_id; }
        entity_id_t* writer_id() const { return m_writer_id; }
        sequence_number_t* writer_sn() const { return m_writer_sn; }
        fragment_number_set_t* fragment_number_set() const { return m_fragment_number_set; }
        count_t* count() const { return m_count; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class vendor_id_t : public kaitai::kstruct {

    public:

        vendor_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vendor_id_t();

    private:
        std::string m_value;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::string value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class fragment_number_set_t : public kaitai::kstruct {

    public:

        fragment_number_set_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~fragment_number_set_t();

    private:
        fragment_number_t* m_bitmap_base;
        uint32_t m_numbits;
        fragment_number_t* m_bitmap;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;
        std::string m__raw_bitmap;
        kaitai::kstream* m__io__raw_bitmap;

    public:
        fragment_number_t* bitmap_base() const { return m_bitmap_base; }
        uint32_t numbits() const { return m_numbits; }
        fragment_number_t* bitmap() const { return m_bitmap; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
        std::string _raw_bitmap() const { return m__raw_bitmap; }
        kaitai::kstream* _io__raw_bitmap() const { return m__io__raw_bitmap; }
    };

    class data_t : public kaitai::kstruct {

    public:

        data_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_t();

    private:
        int16_t m_extra_flags;
        uint16_t m_octets_to_inline_qos;
        entity_id_t* m_reader_id;
        entity_id_t* m_writer_id;
        sequence_number_t* m_writer_sn;
        parameter_list_t* m_inline_qos;
        bool n_inline_qos;

    public:
        bool _is_null_inline_qos() { inline_qos(); return n_inline_qos; };

    private:
        serialized_payload_t* m_serialized_payload;
        bool n_serialized_payload;

    public:
        bool _is_null_serialized_payload() { serialized_payload(); return n_serialized_payload; };

    private:
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:

        /**
         * see 9.4.5.3.2. This protocol version should set all to zero.
         */
        int16_t extra_flags() const { return m_extra_flags; }

        /**
         * \sa 9.4.5.3.2
         */
        uint16_t octets_to_inline_qos() const { return m_octets_to_inline_qos; }
        entity_id_t* reader_id() const { return m_reader_id; }
        entity_id_t* writer_id() const { return m_writer_id; }
        sequence_number_t* writer_sn() const { return m_writer_sn; }

        /**
         * only if Q == 1 means only if QosFlag is set
         */
        parameter_list_t* inline_qos() const { return m_inline_qos; }

        /**
         * only if D==1 or K==1 means only if DataFlag or KeyFlag is set. see 9.4.5.3.1
         */
        serialized_payload_t* serialized_payload() const { return m_serialized_payload; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class info_reply_t : public kaitai::kstruct {

    public:

        info_reply_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~info_reply_t();

    private:
        locator_list_t* m_unicast_locator_list;
        locator_list_t* m_multicast_locator_list;
        bool n_multicast_locator_list;

    public:
        bool _is_null_multicast_locator_list() { multicast_locator_list(); return n_multicast_locator_list; };

    private:
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        locator_list_t* unicast_locator_list() const { return m_unicast_locator_list; }
        locator_list_t* multicast_locator_list() const { return m_multicast_locator_list; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class bitmap_t_t : public kaitai::kstruct {

    public:

        bitmap_t_t(kaitai::kstream* p__io, rtps_t::sequence_number_set_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~bitmap_t_t();

    private:
        int32_t m_value;
        rtps_t* m__root;
        rtps_t::sequence_number_set_t* m__parent;

    public:
        int32_t value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        rtps_t::sequence_number_set_t* _parent() const { return m__parent; }
    };

    class serialized_payload_header_t : public kaitai::kstruct {

    public:

        enum representation_t {
            REPRESENTATION_CDR_LE = 2,
            REPRESENTATION_CDR_BE = 3
        };

        serialized_payload_header_t(kaitai::kstream* p__io, rtps_t::serialized_payload_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~serialized_payload_header_t();

    private:
        uint16_t m_representation_identifier;
        uint16_t m_representation_options;
        rtps_t* m__root;
        rtps_t::serialized_payload_t* m__parent;

    public:
        uint16_t representation_identifier() const { return m_representation_identifier; }
        uint16_t representation_options() const { return m_representation_options; }
        rtps_t* _root() const { return m__root; }
        rtps_t::serialized_payload_t* _parent() const { return m__parent; }
    };

    class parameter_id_t : public kaitai::kstruct {

    public:

        parameter_id_t(kaitai::kstream* p__io, rtps_t::parameter_list_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~parameter_id_t();

    private:
        int16_t m_id;
        rtps_t* m__root;
        rtps_t::parameter_list_t* m__parent;

    public:
        int16_t id() const { return m_id; }
        rtps_t* _root() const { return m__root; }
        rtps_t::parameter_list_t* _parent() const { return m__parent; }
    };

    /**
     * Pad is leaved blank, as specified in 9.4.5.12
     */

    class pad_t : public kaitai::kstruct {

    public:

        pad_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~pad_t();

    private:
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class info_timestamp_t : public kaitai::kstruct {

    public:

        info_timestamp_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~info_timestamp_t();

    private:
        timestamp_t* m_timestamp;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        timestamp_t* timestamp() const { return m_timestamp; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class serialized_payload_t : public kaitai::kstruct {

    public:

        serialized_payload_t(kaitai::kstream* p__io, rtps_t::data_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~serialized_payload_t();

    private:
        serialized_payload_header_t* m_header;
        std::string m_payload;
        rtps_t* m__root;
        rtps_t::data_t* m__parent;

    public:
        serialized_payload_header_t* header() const { return m_header; }
        std::string payload() const { return m_payload; }
        rtps_t* _root() const { return m__root; }
        rtps_t::data_t* _parent() const { return m__parent; }
    };

    class guid_prefix_t : public kaitai::kstruct {

    public:

        guid_prefix_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~guid_prefix_t();

    private:
        uint32_t m_host_id;
        uint32_t m_app_id;
        uint32_t m_instance_id;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t host_id() const { return m_host_id; }
        uint32_t app_id() const { return m_app_id; }
        uint32_t instance_id() const { return m_instance_id; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class entity_id_t : public kaitai::kstruct {

    public:

        entity_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_id_t();

    private:
        bool f_raw_key;
        int32_t m_raw_key;

    public:

        /**
         * Instance Key is first 3-bytes
         */
        int32_t raw_key();

    private:
        bool f_raw_kind;
        int32_t m_raw_kind;

    public:

        /**
         * Instance Key is last byte
         */
        int32_t raw_kind();

    private:
        bool f_kind;
        entity_kind_t m_kind;

    public:
        entity_kind_t kind();

    private:
        uint32_t m_value;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class acknack_t : public kaitai::kstruct {

    public:

        acknack_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~acknack_t();

    private:
        entity_id_t* m_reader_id;
        entity_id_t* m_writer_id;
        sequence_number_set_t* m_reader_sn_state;
        count_t* m_count;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        entity_id_t* reader_id() const { return m_reader_id; }
        entity_id_t* writer_id() const { return m_writer_id; }
        sequence_number_set_t* reader_sn_state() const { return m_reader_sn_state; }
        count_t* count() const { return m_count; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class locator_list_t : public kaitai::kstruct {

    public:

        locator_list_t(kaitai::kstream* p__io, rtps_t::info_reply_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~locator_list_t();

    private:
        locator_t* m_value;
        rtps_t* m__root;
        rtps_t::info_reply_t* m__parent;

    public:
        locator_t* value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        rtps_t::info_reply_t* _parent() const { return m__parent; }
    };

    class gap_t : public kaitai::kstruct {

    public:

        gap_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gap_t();

    private:
        entity_id_t* m_reader_id;
        entity_id_t* m_writer_id;
        sequence_number_t* m_gap_start;
        sequence_number_set_t* m_gap_list;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        entity_id_t* reader_id() const { return m_reader_id; }
        entity_id_t* writer_id() const { return m_writer_id; }
        sequence_number_t* gap_start() const { return m_gap_start; }
        sequence_number_set_t* gap_list() const { return m_gap_list; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class info_destination_t : public kaitai::kstruct {

    public:

        info_destination_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~info_destination_t();

    private:
        guid_prefix_t* m_guid_prefix;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        guid_prefix_t* guid_prefix() const { return m_guid_prefix; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class rtps_submessage_t : public kaitai::kstruct {

    public:

        rtps_submessage_t(kaitai::kstream* p__io, rtps_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~rtps_submessage_t();

    private:
        submessage_header_t* m_header;
        kaitai::kstruct* m_payload;
        bool n_payload;

    public:
        bool _is_null_payload() { payload(); return n_payload; };

    private:
        rtps_t* m__root;
        rtps_t* m__parent;

    public:
        submessage_header_t* header() const { return m_header; }
        kaitai::kstruct* payload() const { return m_payload; }
        rtps_t* _root() const { return m__root; }
        rtps_t* _parent() const { return m__parent; }
    };

    class submessage_header_t : public kaitai::kstruct {

    public:

        submessage_header_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~submessage_header_t();

    private:
        submessage_id_t m_submessage_id;
        uint8_t m_flags;
        uint16_t m_octets_to_next_header;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        submessage_id_t submessage_id() const { return m_submessage_id; }
        uint8_t flags() const { return m_flags; }
        uint16_t octets_to_next_header() const { return m_octets_to_next_header; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

    class locator_t : public kaitai::kstruct {

    public:

        locator_t(kaitai::kstream* p__io, rtps_t::locator_list_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~locator_t();

    private:
        int32_t m_kind;
        uint32_t m_port;
        std::string m_address;
        rtps_t* m__root;
        rtps_t::locator_list_t* m__parent;

    public:
        int32_t kind() const { return m_kind; }
        uint32_t port() const { return m_port; }
        std::string address() const { return m_address; }
        rtps_t* _root() const { return m__root; }
        rtps_t::locator_list_t* _parent() const { return m__parent; }
    };

    class sequence_number_t : public kaitai::kstruct {

    public:

        sequence_number_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sequence_number_t();

    private:
        uint32_t m_high;
        uint32_t m_low;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t high() const { return m_high; }
        uint32_t low() const { return m_low; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class rtps_header_t : public kaitai::kstruct {

    public:

        rtps_header_t(kaitai::kstream* p__io, rtps_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~rtps_header_t();

    private:
        std::string m_magic;
        protocol_version_t* m_protocol_version;
        vendor_id_t* m_vendor_id;
        guid_prefix_t* m_guid_prefix;
        rtps_t* m__root;
        rtps_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        protocol_version_t* protocol_version() const { return m_protocol_version; }
        vendor_id_t* vendor_id() const { return m_vendor_id; }
        guid_prefix_t* guid_prefix() const { return m_guid_prefix; }
        rtps_t* _root() const { return m__root; }
        rtps_t* _parent() const { return m__parent; }
    };

    class parameter_list_t : public kaitai::kstruct {

    public:

        parameter_list_t(kaitai::kstream* p__io, rtps_t::data_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~parameter_list_t();

    private:
        parameter_id_t* m_parameter_id;
        int16_t m_length;
        std::string m_value;
        rtps_t* m__root;
        rtps_t::data_t* m__parent;

    public:
        parameter_id_t* parameter_id() const { return m_parameter_id; }
        int16_t length() const { return m_length; }
        std::string value() const { return m_value; }
        rtps_t* _root() const { return m__root; }
        rtps_t::data_t* _parent() const { return m__parent; }
    };

    class protocol_version_t : public kaitai::kstruct {

    public:

        protocol_version_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~protocol_version_t();

    private:
        uint8_t m_major;
        uint8_t m_minor;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t major() const { return m_major; }
        uint8_t minor() const { return m_minor; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class sequence_number_set_t : public kaitai::kstruct {

    public:

        sequence_number_set_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sequence_number_set_t();

    private:
        sequence_number_t* m_bitmap_base;
        uint32_t m_numbits;
        std::vector<bitmap_t_t*>* m_bitmap;
        rtps_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        sequence_number_t* bitmap_base() const { return m_bitmap_base; }
        uint32_t numbits() const { return m_numbits; }
        std::vector<bitmap_t_t*>* bitmap() const { return m_bitmap; }
        rtps_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class heartbeat_t : public kaitai::kstruct {

    public:

        heartbeat_t(kaitai::kstream* p__io, rtps_t::rtps_submessage_t* p__parent = 0, rtps_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~heartbeat_t();

    private:
        entity_id_t* m_reader_id;
        entity_id_t* m_writer_id;
        sequence_number_t* m_first_sn;
        sequence_number_t* m_last_sn;
        count_t* m_count;
        rtps_t* m__root;
        rtps_t::rtps_submessage_t* m__parent;

    public:
        entity_id_t* reader_id() const { return m_reader_id; }
        entity_id_t* writer_id() const { return m_writer_id; }
        sequence_number_t* first_sn() const { return m_first_sn; }
        sequence_number_t* last_sn() const { return m_last_sn; }
        count_t* count() const { return m_count; }
        rtps_t* _root() const { return m__root; }
        rtps_t::rtps_submessage_t* _parent() const { return m__parent; }
    };

private:
    rtps_header_t* m_header;
    std::vector<rtps_submessage_t*>* m_submessage;
    rtps_t* m__root;
    kaitai::kstruct* m__parent;

public:
    rtps_header_t* header() const { return m_header; }
    std::vector<rtps_submessage_t*>* submessage() const { return m_submessage; }
    rtps_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // RTPS_H_
