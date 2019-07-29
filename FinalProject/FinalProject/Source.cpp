#include "../Common/Border/Border.h"
#include "../Common/Border/DoubleBorder.h"
#include "../Common/Border/NullBorder.h"
#include "../Common/Border/SingleBorder.h"
#include "../Common/EventEngine.h"
#include "../Common/Graphics.h"
#include "../Controls/Button.h"
#include "../Controls/CheckList.h"
#include "../Controls/ComboBox.h"
#include "../Controls/Label.h"
#include "../Controls/MessageBox.h"
#include "../Controls/NumericBox.h"
#include "../Controls/Panel.h"
#include "../Controls/RadioBox.h"
#include "../Controls/textbox.h"

int main(int argc, char** argv)
{
	DoubleBorder* db = new DoubleBorder;
	NullBorder* nb = new NullBorder;
	SingleBorder* sb = new SingleBorder;

	Panel P(0, 0, db, Color::White, Color::Black);
	Button B(0, 10, 10, sb, Color::White, Color::Black, "Show");
	semMessageBox MB(0, 0, 30, db, Color::White, Color::Cyan, "Message", "Ok", "Cancel", &B);
	TextBox TB(40, 0, 10, sb, Color::White, Color::Cyan);
	ComboBox CB(40, 10, sb, Color::White, Color::Cyan);
	CB.addToList("one");
	CB.addToList("two");
	CB.addToList("forty seven");
	CheckList CL(60, 10, 20, db, Color::Purple, Color::White);
	CL.addToList("hello");
	CL.addToList("HELLO");
	CL.addToList("HeLlO");
	RadioBox RB(50, 10, 15, db, Color::Blue, Color::White);
	RB.addToList("qwer");
	RB.addToList("asdf");
	RB.addToList("zxcv");
	Label L(0, 15, 10, nb, Color::White, Color::Black, "Such WOW");
	NumericBox NB(50, 5, 10, 0, sb, Color::White, Color::Black);

	P.addControl(&B);
	P.addControl(&MB);
	P.addControl(&TB);
	P.addControl(&CB);
	P.addControl(&CL);
	P.addControl(&RB);
	P.addControl(&L);
	P.addControl(&NB);
	EventEngine e;
	e.run(P);
	return 0;
}