#include "extractor.h"
#include <fstream>

void extractor::extract() const
{
	std::ofstream output(config_.output_filename);
	for (const auto& entry : fs::directory_iterator(config_.directory_path))
	{
		if (valid(entry))
		{
			write(entry, output);
		}
	}
}

config& extractor::get_config()
{
	return config_;
}

bool extractor::valid(const fs::directory_entry& entry) const
{
	const auto extension = entry.path().extension();
	return config_.extensions.find(extension) != config_.extensions.cend();
}

void extractor::write_filename(const fs::directory_entry& entry, std::ofstream& output) const
{
	const auto path = entry.path().string();
	output << config_.filename_prefix << path << config_.filename_suffix;
}

void extractor::write_content(const fs::directory_entry& entry, std::ofstream& output) const
{
	std::ifstream input(entry.path());
	std::string buffer;
	while (std::getline(input, buffer))
	{
		output << buffer << "\n";
	}
}

void extractor::write_divider(std::ofstream& output) const
{
	output << config_.file_divider;
}

void extractor::write(const fs::directory_entry& entry, std::ofstream& output) const
{
	write_filename(entry, output);
	write_content(entry, output);
	write_divider(output);
}
