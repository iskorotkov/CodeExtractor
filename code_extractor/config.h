#pragma once
#include <string>
#include <set>
#include <filesystem>

namespace fs = std::filesystem;

struct config
{
	std::string directory_path = "";
	std::string filename_prefix = "// ";
	std::string filename_suffix = "\n";
	std::string file_divider = "\n";
	std::string output_filename = "extracted.txt";
	std::set<fs::path> extensions{ ".h", ".cpp", ".cs" };
};
