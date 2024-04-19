# ----------------------------
# Makefile Options
# ----------------------------

NAME = GRID
ICON = icon.png
DESCRIPTION = "A Digital Frontier"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz -std=c++17

# ----------------------------

include $(shell cedev-config --makefile)
