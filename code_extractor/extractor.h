#pragma once
#include <filesystem>
#include "config.h"

namespace fs = std::filesystem;

class extractor
{
public:
	void extract() const;
	config& get_config();

private:
	config config_;

	bool valid(const fs::directory_entry& entry) const;
	void write_filename(const fs::directory_entry& entry, std::ofstream& output) const;
	void write_content(const fs::directory_entry& entry, std::ofstream& output) const;
	void write_divider(std::ofstream& output) const;
	void write(const fs::directory_entry& entry, std::ofstream& output) const;
};
