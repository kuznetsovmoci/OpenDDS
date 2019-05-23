#pragma once

#include "Common.h"
#include "ConfigSectionManager.h"
#include "DiscoveryManager.h"
#include "TransportInstanceManager.h"
#include "ParticipantManager.h"

namespace Builder {

class Stool_Builder_Export Process {
public:
  explicit Process(const ProcessConfig& config);
  ~Process();

  void enable_dds_entities();

  ProcessReport& get_report() { return report_; }
  const ProcessReport& get_report() const { return report_; }

  ReaderMap& get_reader_map() { return reader_map_; }
  const ReaderMap& get_reader_map() const { return reader_map_; }

  WriterMap& get_writer_map() { return writer_map_; }
  const WriterMap& get_writer_map() const { return writer_map_; }

protected:
  ProcessReport report_;
  ReaderMap reader_map_;
  WriterMap writer_map_;
  std::shared_ptr<ConfigSectionManager> config_sections_;
  std::shared_ptr<DiscoveryManager> discoveries_;
  std::shared_ptr<TransportInstanceManager> instances_;
  std::shared_ptr<ParticipantManager> participants_;
};

}
