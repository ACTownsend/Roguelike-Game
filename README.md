# Rogue
Rogue-like game written in c++

HOW TO SOLVE THE LIBSQLITE ERROR
1. Open Visual Studio 2017 and create a new project - C++ and Windows Console Application.

2. Optional step - go to your project, right click and select Properties, then C++ and Precompiled headers. First option at the top - click on it and select Not Using Precompiled Headers

3. Download all the aformentioned files from Moodle. 

4. Add the files to the project as follows (based on the path to your project - C:/Users/YOURUSERNAME/source/repos/PROJECTNAME):

     In there you will have another folder with your PROJECTNAME - in there add as follows:

    1) a folder "include" where you put the sqlite3.h and libsqlite.hpp

    2) a folder "lib" where you put libsqlite.a

    3) your database file (firefly etc)

5. In your PROJECTNAME/Debug folder add the sqlite3.dll file

6. Go to Project, right click and Properties; Go to C/C++ and General and then Additional Include Directories - add include in the cell (name of the folder previously created)

7. Go to Project, right click and Properties; Go to Linker and General and then Additionally Library Directories - add lib in the cell (name of the folder previously created)

8. Go to Project, right click and Properties; Go to Linker, then Input and Additional Dependencies - add libsqlite3.a in the cell (leave the ones that were there before as well).
