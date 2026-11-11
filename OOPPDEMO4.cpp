#include <bits/stdc++.h>
using namespace std;

///======================================================
/// MARUF : COLOURS
///======================================================

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"


///======================================================
/// MARUF : HELPER / UI FUNCTIONS
///======================================================

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressEnterToContinue()
{
    cout << "\n" << YELLOW << "Press Enter to return to menu..." << RESET;
    cin.get();
}


///======================================================
/// ZUNAED : FILE HANDLING HELPER FUNCTION
///======================================================

// Helper function to split delimited file lines safely
vector<string> split(const string& str, char delimiter)
{
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}


///======================================================
/// ZUNAED : TEMPLATE CLASS
///======================================================

template <class T>
class Display
{
public:
    static void show(const T& value)
    {
        cout << value << endl;
    }
};


///======================================================
/// MUNTASIR + MARUF : BASE CLASS
///======================================================

class Person
{
protected:
    string id;
    string name;
    string department;

public:
    Person() : id(""), name(""), department("") {}

    Person(string id, string name, string department)
        : id(id), name(name), department(department) {}

    virtual void input() = 0;
    virtual void display() const = 0;

    string getID() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }

    virtual ~Person() {}
};


///======================================================
/// MUNTASIR : STUDENT CLASS
///======================================================

class Student : public Person
{
private:
    string researchTopic;
    int semester;
    double cgpa;

public:
    Student()
        : Person(), researchTopic(""), semester(0), cgpa(0.0) {}

    Student(string id, string name, string department,
            string topic, int semester, double cgpa)
        : Person(id, name, department),
          researchTopic(topic),
          semester(semester),
          cgpa(cgpa) {}

    void input() override
    {
        cout << CYAN << "Student ID     : " << RESET;
        getline(cin, id);

        cout << CYAN << "Name           : " << RESET;
        getline(cin, name);

        cout << CYAN << "Department     : " << RESET;
        getline(cin, department);

        cout << CYAN << "Research Topic : " << RESET;
        getline(cin, researchTopic);

        cout << CYAN << "Semester       : " << RESET;

        while (!(cin >> semester))
        {
            cout << RED
                 << "Invalid input! Enter numeric semester: "
                 << RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << CYAN << "CGPA           : " << RESET;

        while (!(cin >> cgpa))
        {
            cout << RED
                 << "Invalid input! Enter numeric CGPA: "
                 << RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const override
    {
        cout << BLUE
             << "------------------------------------------"
             << RESET << "\n";

        cout << WHITE << "  ID             : "
             << RESET << id << endl;

        cout << WHITE << "  Name           : "
             << RESET << name << endl;

        cout << WHITE << "  Department     : "
             << RESET << department << endl;

        cout << WHITE << "  Research Topic : "
             << RESET << researchTopic << endl;

        cout << WHITE << "  Semester       : "
             << RESET << semester << endl;

        cout << WHITE << "  CGPA           : "
             << RESET << fixed << setprecision(2)
             << cgpa << endl;
    }

    string getResearchTopic() const
    {
        return researchTopic;
    }

    int getSemester() const
    {
        return semester;
    }

    double getCGPA() const
    {
        return cgpa;
    }

    ~Student() override {}
};


///======================================================
/// MARUF : FACULTY CLASS
///======================================================

class Faculty : public Person
{
private:
    string designation;
    string specialization;

public:
    Faculty()
        : Person(), designation(""), specialization("") {}

    Faculty(string id, string name, string department,
            string designation, string specialization)
        : Person(id, name, department),
          designation(designation),
          specialization(specialization) {}

    void input() override
    {
        cout << CYAN << "Faculty ID     : " << RESET;
        getline(cin, id);

        cout << CYAN << "Name           : " << RESET;
        getline(cin, name);

        cout << CYAN << "Department     : " << RESET;
        getline(cin, department);

        cout << CYAN << "Designation    : " << RESET;
        getline(cin, designation);

        cout << CYAN << "Specialization : " << RESET;
        getline(cin, specialization);
    }

    void display() const override
    {
        cout << BLUE
             << "------------------------------------------"
             << RESET << "\n";

        cout << WHITE << "  ID             : "
             << RESET << id << endl;

        cout << WHITE << "  Name           : "
             << RESET << name << endl;

        cout << WHITE << "  Department     : "
             << RESET << department << endl;

        cout << WHITE << "  Designation    : "
             << RESET << designation << endl;

        cout << WHITE << "  Specialization : "
             << RESET << specialization << endl;
    }

    string getDesignation() const
    {
        return designation;
    }

    string getSpecialization() const
    {
        return specialization;
    }

    ~Faculty() override {}
};


///======================================================
/// HOSSAIN : RESEARCH PROJECT CLASS
///======================================================

class ResearchProject
{
private:
    string projectID;
    string title;
    string studentID;
    string supervisorID;
    string status;
    double budget;

public:
    ResearchProject()
        : projectID(""),
          title(""),
          studentID(""),
          supervisorID(""),
          status("Ongoing"),
          budget(0.0) {}

    ResearchProject(string pid, string title, string sid,
                    string fid, string status, double budget)
        : projectID(pid),
          title(title),
          studentID(sid),
          supervisorID(fid),
          status(status),
          budget(budget) {}

    void input()
    {
        cout << CYAN << "Project ID    : " << RESET;
        getline(cin, projectID);

        cout << CYAN << "Project Title : " << RESET;
        getline(cin, title);

        cout << CYAN << "Student ID    : " << RESET;
        getline(cin, studentID);

        cout << CYAN << "Supervisor ID : " << RESET;
        getline(cin, supervisorID);

        cout << CYAN << "Status        : " << RESET;
        getline(cin, status);

        cout << CYAN << "Budget        : " << RESET;

        while (!(cin >> budget))
        {
            cout << RED
                 << "Invalid input! Enter numeric budget: "
                 << RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const
    {
        cout << BLUE
             << "------------------------------------------"
             << RESET << "\n";

        cout << WHITE << "  Project ID    : "
             << RESET << projectID << endl;

        cout << WHITE << "  Title         : "
             << RESET << title << endl;

        cout << WHITE << "  Student ID    : "
             << RESET << studentID << endl;

        cout << WHITE << "  Supervisor ID : "
             << RESET << supervisorID << endl;

        cout << WHITE << "  Status        : "
             << RESET << status << endl;

        cout << WHITE << "  Budget        : BDT "
             << RESET << fixed << setprecision(2)
             << budget << endl;
    }

    string getProjectID() const
    {
        return projectID;
    }

    string getTitle() const
    {
        return title;
    }

    string getStudentID() const
    {
        return studentID;
    }

    string getSupervisorID() const
    {
        return supervisorID;
    }

    string getStatus() const
    {
        return status;
    }

    double getBudget() const
    {
        return budget;
    }
};


///======================================================
/// LIU : PUBLICATION CLASS
///======================================================

class Publication
{
private:
    string publicationID;
    string title;
    string journal;
    int year;

public:
    Publication()
        : publicationID(""),
          title(""),
          journal(""),
          year(0) {}

    Publication(string id, string title,
                string journal, int year)
        : publicationID(id),
          title(title),
          journal(journal),
          year(year) {}

    void input()
    {
        cout << CYAN << "Publication ID : " << RESET;
        getline(cin, publicationID);

        cout << CYAN << "Title          : " << RESET;
        getline(cin, title);

        cout << CYAN << "Journal        : " << RESET;
        getline(cin, journal);

        cout << CYAN << "Year           : " << RESET;

        while (!(cin >> year))
        {
            cout << RED
                 << "Invalid input! Enter numeric year: "
                 << RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const
    {
        cout << BLUE
             << "------------------------------------------"
             << RESET << "\n";

        cout << WHITE << "  Publication ID : "
             << RESET << publicationID << endl;

        cout << WHITE << "  Title          : "
             << RESET << title << endl;

        cout << WHITE << "  Journal        : "
             << RESET << journal << endl;

        cout << WHITE << "  Year           : "
             << RESET << year << endl;
    }

    string getPublicationID() const
    {
        return publicationID;
    }

    string getTitle() const
    {
        return title;
    }

    string getJournal() const
    {
        return journal;
    }

    int getYear() const
    {
        return year;
    }
};


///======================================================
/// ZUNAED : GLOBAL DATA
///======================================================

vector<Student> students;
vector<Faculty> faculties;
vector<ResearchProject> projects;
vector<Publication> publications;


///======================================================
/// ZUNAED : EXCEPTION HANDLING
///======================================================

void checkID(const string& id)
{
    if (id.empty())
    {
        throw runtime_error("Error: ID cannot be empty!");
    }
}

void checkBudget(double amount)
{
    if (amount < 0)
    {
        throw runtime_error("Error: Invalid Budget!");
    }
}


///======================================================
/// ZUNAED : FILE HANDLING
///======================================================

void saveData()
{
    ofstream file("research_data.txt");

    if (!file.is_open())
    {
        cout << RED
             << "\nFailed to open file for writing.\n"
             << RESET;

        return;
    }

    file << "[STUDENTS]\n";

    for (const auto& s : students)
    {
        file << s.getID() << "|"
             << s.getName() << "|"
             << s.getDepartment() << "|"
             << s.getResearchTopic() << "|"
             << s.getSemester() << "|"
             << s.getCGPA() << "\n";
    }

    file << "\n[FACULTIES]\n";

    for (const auto& f : faculties)
    {
        file << f.getID() << "|"
             << f.getName() << "|"
             << f.getDepartment() << "|"
             << f.getDesignation() << "|"
             << f.getSpecialization() << "\n";
    }

    file << "\n[PROJECTS]\n";

    for (const auto& p : projects)
    {
        file << p.getProjectID() << "|"
             << p.getTitle() << "|"
             << p.getStudentID() << "|"
             << p.getSupervisorID() << "|"
             << p.getStatus() << "|"
             << p.getBudget() << "\n";
    }

    file << "\n[PUBLICATIONS]\n";

    for (const auto& p : publications)
    {
        file << p.getPublicationID() << "|"
             << p.getTitle() << "|"
             << p.getJournal() << "|"
             << p.getYear() << "\n";
    }

    file.close();

    cout << GREEN
         << "\nData Saved Successfully to 'research_data.txt'.\n"
         << RESET;
}


void loadData()
{
    ifstream file("research_data.txt");

    if (!file.is_open())
    {
        // File doesn't exist yet
        return;
    }

    students.clear();
    faculties.clear();
    projects.clear();
    publications.clear();

    string line;

    enum Section
    {
        NONE,
        STUDENTS,
        FACULTIES,
        PROJECTS,
        PUBLICATIONS
    };

    Section currentSection = NONE;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        if (line == "[STUDENTS]")
        {
            currentSection = STUDENTS;
            continue;
        }

        if (line == "[FACULTIES]")
        {
            currentSection = FACULTIES;
            continue;
        }

        if (line == "[PROJECTS]")
        {
            currentSection = PROJECTS;
            continue;
        }

        if (line == "[PUBLICATIONS]")
        {
            currentSection = PUBLICATIONS;
            continue;
        }

        vector<string> parts = split(line, '|');

        try
        {
            if (currentSection == STUDENTS &&
                parts.size() == 6)
            {
                students.emplace_back(
                    parts[0],
                    parts[1],
                    parts[2],
                    parts[3],
                    stoi(parts[4]),
                    stod(parts[5])
                );
            }

            else if (currentSection == FACULTIES &&
                     parts.size() == 5)
            {
                faculties.emplace_back(
                    parts[0],
                    parts[1],
                    parts[2],
                    parts[3],
                    parts[4]
                );
            }

            else if (currentSection == PROJECTS &&
                     parts.size() == 6)
            {
                projects.emplace_back(
                    parts[0],
                    parts[1],
                    parts[2],
                    parts[3],
                    parts[4],
                    stod(parts[5])
                );
            }

            else if (currentSection == PUBLICATIONS &&
                     parts.size() == 4)
            {
                publications.emplace_back(
                    parts[0],
                    parts[1],
                    parts[2],
                    stoi(parts[3])
                );
            }
        }

        catch (const exception&)
        {
            // Skip corrupted rows silently
            continue;
        }
    }

    file.close();
}


///======================================================
/// MARUF : HELPER / UI FUNCTION
///======================================================

void printHeader(const string& title)
{
    clearScreen();

    cout << MAGENTA
         << "==========================================\n"
         << RESET;

    cout << BOLD << WHITE
         << "         " << title << "\n"
         << RESET;

    cout << MAGENTA
         << "==========================================\n\n"
         << RESET;
}


///======================================================
/// MUNTASIR : HOMEPAGE UI
///======================================================

void showHomePage()
{
    clearScreen();

    cout << "\n\n";

    cout << CYAN
         << "========================================================\n"
         << RESET;

    cout << BOLD << WHITE
         << "         UNIVERSITY RESEARCH MANAGEMENT SYSTEM         \n"
         << RESET;

    cout << CYAN
         << "========================================================\n\n\n"
         << RESET;

    cout << "                       "
         << BOLD << GREEN
         << "[ PROCEED ]"
         << RESET << "\n\n\n";

    cout << YELLOW
         << "           Press Enter to Open Options Box...          "
         << RESET;

    cin.get();
}


///======================================================
/// MUNTASIR : MENU UI
///======================================================

void showMenuBox()
{
    clearScreen();

    cout << BLUE
         << "+------------------------------------------------------+\n"
         << RESET;

    cout << BLUE << "| "
         << BOLD << WHITE
         << "                  SELECT AN OPTION                  "
         << BLUE << " |\n"
         << RESET;

    cout << BLUE
         << "+------------------------------------------------------+\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "1. Add Student"
         << RESET
         << "                                       "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "2. View Students"
         << RESET
         << "                                     "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "3. Add Faculty"
         << RESET
         << "                                       "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "4. View Faculty"
         << RESET
         << "                                      "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "5. Add Research Project"
         << RESET
         << "                              "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "6. View Research Projects"
         << RESET
         << "                            "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "7. Add Publication"
         << RESET
         << "                                   "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << YELLOW << "8. View Publications"
         << RESET
         << "                                 "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << GREEN << "9. Save Data"
         << RESET
         << "                                         "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE << "| "
         << RED << "10. Exit"
         << RESET
         << "                                             "
         << BLUE << "|\n"
         << RESET;

    cout << BLUE
         << "+------------------------------------------------------+\n"
         << RESET;

    cout << CYAN
         << "\nEnter Choice [1-10]: "
         << RESET;
}


///======================================================
/// HOSSAIN : ADD / VIEW RESEARCH PROJECT FUNCTIONALITY
///======================================================

void addProject()
{
    printHeader("ADD RESEARCH PROJECT");

    try
    {
        ResearchProject p;

        p.input();

        checkID(p.getProjectID());

        checkBudget(p.getBudget());

        projects.push_back(p);

        cout << GREEN
             << "\nProject Added Successfully!\n"
             << RESET;
    }

    catch (const exception& e)
    {
        cout << RED
             << "\n" << e.what()
             << RESET << endl;
    }

    pressEnterToContinue();
}


void viewProjects()
{
    printHeader("RESEARCH PROJECTS DIRECTORY");

    if (projects.empty())
    {
        cout << RED
             << "No projects found in record.\n"
             << RESET;
    }
    else
    {
        for (const auto& p : projects)
            p.display();
    }

    pressEnterToContinue();
}


///======================================================
/// LIU : ADD / VIEW PUBLICATION FUNCTIONALITY
///======================================================

void addPublication()
{
    printHeader("ADD PUBLICATION");

    try
    {
        Publication p;

        p.input();

        checkID(p.getPublicationID());

        publications.push_back(p);

        cout << GREEN
             << "\nPublication Added Successfully!\n"
             << RESET;
    }

    catch (const exception& e)
    {
        cout << RED
             << "\n" << e.what()
             << RESET << endl;
    }

    pressEnterToContinue();
}


void viewPublications()
{
    printHeader("PUBLICATIONS DIRECTORY");

    if (publications.empty())
    {
        cout << RED
             << "No publications found in record.\n"
             << RESET;
    }
    else
    {
        for (const auto& p : publications)
            p.display();
    }

    pressEnterToContinue();
}


///======================================================
/// MUNTASIR : STUDENT FUNCTIONALITY
///======================================================

void addStudent()
{
    printHeader("ADD NEW STUDENT");

    try
    {
        Student s;

        s.input();

        checkID(s.getID());

        students.push_back(s);

        cout << GREEN
             << "\nStudent Added Successfully!\n"
             << RESET;
    }

    catch (const exception& e)
    {
        cout << RED
             << "\n" << e.what()
             << RESET << endl;
    }

    pressEnterToContinue();
}


void viewStudents()
{
    printHeader("STUDENT DIRECTORY");

    if (students.empty())
    {
        cout << RED
             << "No students found in record.\n"
             << RESET;
    }
    else
    {
        for (const auto& s : students)
            s.display();
    }

    pressEnterToContinue();
}


///======================================================
/// MARUF : FACULTY FUNCTIONALITY
///======================================================

void addFaculty()
{
    printHeader("ADD NEW FACULTY");

    try
    {
        Faculty f;

        f.input();

        checkID(f.getID());

        faculties.push_back(f);

        cout << GREEN
             << "\nFaculty Added Successfully!\n"
             << RESET;
    }

    catch (const exception& e)
    {
        cout << RED
             << "\n" << e.what()
             << RESET << endl;
    }

    pressEnterToContinue();
}


void viewFaculty()
{
    printHeader("FACULTY DIRECTORY");

    if (faculties.empty())
    {
        cout << RED
             << "No faculty members found in record.\n"
             << RESET;
    }
    else
    {
        for (const auto& f : faculties)
            f.display();
    }

    pressEnterToContinue();
}


///======================================================
/// ZUNAED : SAVE DATA FUNCTIONALITY
///======================================================

void handleSaveData()
{
    printHeader("SAVE DATA TO FILE");

    saveData();

    pressEnterToContinue();
}


///======================================================
/// ZUNAED : MAIN MENU / PROGRAM FLOW
///======================================================

int main()
{
    // Load existing records from research_data.txt on startup
    loadData();

    // Display homepage
    showHomePage();

    int choice = 0;

    do
    {
        showMenuBox();

        if (!(cin >> choice))
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        // Clear newline from input buffer
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            viewStudents();
            break;

        case 3:
            addFaculty();
            break;

        case 4:
            viewFaculty();
            break;

        case 5:
            addProject();
            break;

        case 6:
            viewProjects();
            break;

        case 7:
            addPublication();
            break;

        case 8:
            viewPublications();
            break;

        case 9:
            handleSaveData();
            break;

        case 10:
            clearScreen();

            cout << GREEN
                 << "\nThank you for using University Research Management System. Goodbye!\n\n"
                 << RESET;

            break;

        default:
            break;
        }

    } while (choice != 10);

    return 0;
}


