#include "enthusiasm/inheritance/ISAInheritance.h"

int main() {
    NoteBookComputer noteBookComputer("이수종", 5);
    TabletNotebook tabletNotebook("정수영", 5, "ISE-241-242");
    noteBookComputer.movingCal();
    tabletNotebook.write("ISE-241-242");
    return 0;
}