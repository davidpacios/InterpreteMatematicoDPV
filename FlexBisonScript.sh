#!/bin/bash

bison -d -Wconflicts-sr syntacticParser.y --output=./src/syntacticParser.tab.c --header=./includes/syntacticParser.tab.h

flex --header-file="./includes/lexicalAnalysis.yy.h" --outfile="./src/lexicalAnalysis.yy.c" lexicalAnalysis.l

echo "Flex y Bison compilados con éxito."
