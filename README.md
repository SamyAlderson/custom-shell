# custom-shell

A customizable command-line shell implemented in C, empowering users to tailor their interaction with the operating system.

## Overview

custom-shell is a highly flexible and personalized shell designed to overcome the limitations of traditional shells. By leveraging a modular architecture and a robust parser, this project provides an exceptional user experience, enabling users to craft their ideal command-line interface. With custom-shell, users can tailor their shell to suit their workflow, streamlining productivity and efficiency. This project is ideal for developers, system administrators, and power users seeking a high degree of customization.

## Features

* **Modular Architecture**: custom-shell is built using a modular design, allowing users to easily extend or modify existing features.
* **Robust Parser**: A high-performance parser ensures accurate command execution, minimizing errors and improving overall reliability.
* **Command History**: Users can navigate through their command history with ease, reducing the need for manual note-taking.
* **Autocomplete**: Intelligently suggests commands and arguments, saving time and effort.
* **Customizable Keyboard Shortcuts**: Users can define their own keyboard shortcuts to streamline their workflow.
* **Syntax Highlighting**: Enhances readability by visually distinguishing different parts of the command syntax.
* **Extensive Configuration Options**: Users can customize the shell to fit their preferences, from font sizes to command completion settings.

## Getting Started

### Prerequisites

* C compiler (gcc or clang)
* Make utility (make)
* Git version control system

### Installation

```bash
# Clone the repository
git clone https://github.com/tonydelrio/custom-shell.git

# Navigate to the project directory
cd custom-shell

# Build the shell
make

# Install the shell
sudo make install
```

### Usage

```bash
# Launch the custom-shell
custom-shell

# Execute a command
custom-shell> ls -l

# Navigate through command history
custom-shell> history

# Use autocomplete
custom-shell> cd /ho
custom-shell> cd /home/user
```

## Architecture

The project is structured into five main files:

* `src/parser.c`: Handles command parsing and execution.
* `src/commands.c`: Manages command execution and history.
* `src/history.c`: Provides functionality for navigating through command history.
* `src/shell.c`: Acts as the main entry point for the shell, handling user input and interaction.
* `src/autocomplete.c`: Offers intelligent command suggestion and completion.

## API Reference

No public APIs are exposed by this project. Instead, users interact with the shell through a custom command-line interface.

## Testing

```bash
# Run tests
make test
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Commit changes
4. Push and open a pull request

## License

custom-shell is licensed under the MIT License.