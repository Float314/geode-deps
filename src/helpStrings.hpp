#ifndef HELP_STRINGS_HPP
#define HELP_STRINGS_HPP

#include <string> 
#include <format> 
#include <iostream>
#include <chrono>

void helpStr() {
    auto fmtstr = R"md(
geode-deps - Geode dependency manager 

Usage: 
    geode-deps [arg]

Arguments: 
add [id]       Add a dependency
remove [id]    Remove a dependency
help           Shows this message
help --license Shows under what license is this tool 
               under. (GNU LGPL)

    )md";
    std::cout << fmtstr << std::endl;
}

void licenseStr() {
    const auto now = std::chrono::system_clock::now();
    const auto year = std::chrono::year_month_day{
        std::chrono::floor<std::chrono::days>(now)
    }.year();

    auto licStr = std::format(R"md(
Licensed under the GNU Lesser General Public License v3.0
Copyright (C) {}, Float314 and contributors

This program is free software: you can redistribute it and/or modify
it under the terms of the **GNU Lesser General Public License** as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

)md", static_cast<int>(year));

    std::cout << licStr 
    << "\033[32mLGPL "
    << "\033[1;92m <v3> \n"
    << "\033[32mFree as in Freedom!"
    << "\033[0m\n"<< std::endl;    
}
#endif