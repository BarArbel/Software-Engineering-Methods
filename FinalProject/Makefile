CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Border/Border.o Common/Border/DoubleBorder.o Common/Border/NullBorder.o Common/Border/SingleBorder.o Common/Control.o Common/EventEngine.o Common/Graphics.o Controls/Button.o Controls/CheckList.o Controls/ComboBox.o Controls/Label.o Controls/ListItem.o Controls/MessageBox.o Controls/NumericBox.o Controls/Panel.o Controls/RadioBox.o Controls/textbox.o FinalProject/Source.o
%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe


