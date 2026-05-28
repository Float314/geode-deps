# geode-deps

A CLI dependency manager for [Geode SDK](https://geode-sdk.org/) mods - because manually editing `mod.json` every time you add an API gets old fast.

## Install

Install Binaries to the system PATH. (installation steps soon)

## Usage

```bash
# Add a dependency to your mod
geode-deps add cvolton.level-id-api

# Remove a dependency
geode-deps remove geode.custom-keybinds
```

Running `add` will fetch the mod's metadata and automatically update your `mod.json` with the correct dependency entry and version.

## Why?

The Geode ecosystem has a growing number of mod APIs (~19 and not 1900 and counting). Manually hunting down the right mod ID, version string, and JSON syntax every time you want to depend on one is tedious. This tool automates the lookup and injection so you can get back to actually building your mod.

## Dependencies

- Matjson (For JSON, thought would be good cause Geode-sdk Tools)
- Result (idk but req.d by matjson)

## License

Licensed under the GNU LGPL v3.0

Copyright (C) 2026, Float314

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

<img src="https://www.gnu.org/graphics/lgplv3-with-text-154x68.png" alt="All hail GNU LGPL v3">

## Contributing

PRs and issues welcome. If an API isn't being picked up correctly, open an issue with the mod ID and I'll take a look.

## Legal Warning

This project is NOT a part of the core geode-sdk. Its just an extra tool. Though if the Geode Lead-devs are impressed, i dont mind giving them the project ;) 