#!/bin/sh

if (( $# > 2 )); then
	echo "Error: número de argumentos incorrecto"
	exit 1
fi
if [ $# -eq 0 ]; then
	find . -maxdepth 1 -type f ! -name ".*" | xargs du -b 2>/dev/null | sort -n | head -n 1 | cut -f2
	exit 0
fi
if[ $# -eq 1 ]; then
        find . -maxdepth 1 -type f ! -name ".*" | xargs du -b 2>/dev/null | sort -n | tail -n 1 | cut -f2
        exit 0
fi

if[ "$1"="-r"]; then
	find . -tyep f | xargs du -b 2>/dev/null | sort -n | head -n 1 |cut -f2
	exit 0
fi
echo "Error: Opción no valida"
exit 1
fi
if[$# -eq2]; then 
	if[ "$1" = "-r"] && ["$2" = "-b"]; then
		find . -type f | xargs du -b 2>/dev/null | sort -n | tail -n 1| cut -f2
		exit 0
	fi
	if["$1" = "-b"] && ["$2" = "-r"];then
		find . -type f | xargs du -b 2>/dev/null | sort -n | tail -n 1 | cut -f2
		exit 0
	fi
	echo "Error: opción no valida" 
	exit 1
fi
