#include "../includes/symbolsTable.h"
#include "../includes/syntacticParser.tab.h"
int main() {
    initSymbolsTable();

    yyparse();

    destroySymbolsTable();
}
