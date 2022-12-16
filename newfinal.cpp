#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
void printList();
string getTypeName(int);
struct jobs
{
    long long int jid = time(NULL);
    long long int pid;
    long long int did;
    time_t start_time = time(NULL);
    int duration;
    time_t end_time = time(NULL);
};

class doctor
{
private:
    string fname;
    string lname;
    long long int did;
    int tid;
    int totalTime = 0;
    int patients = 0;
    vector<jobs> appointments;

public:
    string getLname()
    {
        return this->lname;
    }
    void setLname(string lname)
    {
        this->lname = lname;
    }
    string getFname()
    {
        return this->fname;
    }
    void setFname(string fname)
    {
        this->fname = fname;
    }
    long long int getDid() { return this->did; }
    void setDid(long long int did)
    {
        this->did = did;
    }
    int getType()
    {
        return this->tid;
    }
    void setType(int tid)
    {
        this->tid = tid;
    }
    int getPatients()
    {
        return this->patients;
    }
    void setPatients()
    {
        this->patients++;
    }
    int getDuration()
    {
        return this->totalTime;
    }
    void setDuration(int duration)
    {
        this->totalTime += duration / 60;
    }
    bool check(jobs *temp, char e)
    {
        srand(time(0));
        if (e == 'y')
        {
            int hrs, mins;
            cout << "Please confirm current time\n";
            cout << "Please enter hours in 24 hour format :- ";
            cin >> hrs;
            cout << "Please enter minutes minutes :- ";
            cin >> mins;
            time_t now = time(NULL);
            struct tm *start = localtime(&now);
            int duration = (rand() % 21 + 10) * 60;
            temp->duration = duration;
            setDuration(temp->duration);
            setPatients();
            if (this->appointments.size() == 0)
            {
                start->tm_hour = 10;
                start->tm_min = 0;
                start->tm_sec = 0;
            }
            else
            {
                start->tm_hour = hrs;
                start->tm_min = mins;
                start->tm_sec = 0;
            }
            temp->start_time = mktime(start);
            int i = 0;
            while (this->appointments[i].end_time <= temp->start_time)
                i++;
            temp->start_time = this->appointments[i].end_time;
            temp->end_time = temp->start_time + duration;
            this->appointments.insert(this->appointments.begin() + i++, *temp);
            i++;
            while (i < this->appointments.size())
            {
                this->appointments[i].start_time += duration;
                this->appointments[i].end_time += duration;
                i++;
            }
        }
        else
        {
            if (getDuration() <= 480 && getPatients() < 8)
            {
                cout << "Doctor is available\n";
                int duration = (rand() % 21 + 10) * 60;
                if (this->appointments.size() == 0)
                {
                    time_t now = time(NULL);
                    struct tm *start = localtime(&now);
                    start->tm_hour = 10;
                    start->tm_min = 0;
                    start->tm_sec = 0;
                    temp->start_time = mktime(start);
                }
                else
                    temp->start_time = this->appointments[this->appointments.size() - 1].end_time;
                temp->duration = duration;
                temp->end_time = temp->start_time + duration;
                setDuration(temp->duration);
                setPatients();
                this->appointments.push_back(*temp);
                cout << "Appointment booked\n";
                return 1;
            }
            else
                cout << "Sorry, doctor there is no time slot left\n";
        }
        return 0;
    }
    void printAppointments()
    {
        if (this->appointments.size() == 0)
            cout << "Doctor has no appointments\n";
        else
        {
            for (int i = 0; i < this->appointments.size(); i++)
            {
                jobs temp = this->appointments[i];
                struct tm *st = localtime(&temp.start_time);
                struct tm *et = localtime(&temp.end_time);
                cout << "Appointment : " << i + 1 << endl;
                cout << "Job Id : " << temp.jid << endl;
                cout << "Patient Id : " << temp.pid << endl;
                cout << "Start date and time : " << ctime(&temp.start_time) << endl;
                cout << "End date and time : " << ctime(&temp.end_time) << endl;
                cout << "Appointment duration : " << temp.duration / 60 << endl;
            }
        }
    }
    void printPartialDoctor()
    {
        cout << "First name : " << getFname() << endl;
        cout << "Last name : " << getLname() << endl;
        cout << "Doctor Id : " << getDid() << endl;
        cout << endl;
    }
    void setTypeid()
    {
        int tempid;
        cout << "\nTypes\n";
        printList();
        cout << "Enter the number corresponding to the type : ";
        cin >> tempid;
        tid = tempid - 1;
    }
    void PrintDoctor()
    {
        cout << "First name : " << getFname() << endl;
        cout << "Last name : " << getLname() << endl;
        cout << "Type : " << getTypeName(this->getType()) << endl;
        cout << "Doctor Id " << getDid() << endl;
        cout << "No of appointments scheduled : " << getPatients()
             << endl;
        cout << "Total working hours : " << (getDuration() / 60)
             << "h " << (getDuration() % 60) << "m\n";
        cout << "\nCurrent Schedule\n\n";
        printAppointments();
        cout << endl;
    }
    doctor()
    {
        string fname, lname;
        cout << "Enter first name : ";
        cin >> fname;
        cout << "Enter last name : ";
        cin >> lname;
        setFname(fname);
        setLname(lname);
        this->did = time(NULL);
        setTypeid();
    }
};
struct datalist
{
    string type;
    vector<doctor> did;
};
vector<datalist> tlist{
    {"Allergists/Immunologists"},
    {"Anesthesiologists"},
    {"Cardiologists"},
    {"Colon and Rectal Surgeons"},
    {"Critical Care Medicine Specialists"},
    {"Dermatologists"},
    {"Endocrinologists"},
    {"Emergency Medicine Specialists"},
    {"Family Physicians"},
    {"Gastroenterologists"},
    {"Geriatric Medicine Specialists"},
    {"Hematologists"},
    {"Hospice and Palliative Medicine Specialists"},
    {"Infectious Disease Specialists"},
    {"Internists"},
    {"Medical Geneticists"},
    {"Nephrologists"},
    {"Neurologists"},
    {"Obstetricians and Gynecologists"},
    {"Oncologists"},
    {"Ophthalmologists"},
    {"Osteopaths"},
    {"Otolaryngologists"},
    {"Pathologists"},
    {"Pediatricians"},
    {"Physiatrists"},
    {"Plastic Surgeons"},
    {"Podiatrists"},
    {"Preventive Medicine Specialists"},
    {"Psychiatrists"},
    {"Pulmonologists"},
    {"Radiologists"},
    {"Rheumatologists"},
    {"Sleep Medicine Specialists"},
    {"Sports Medicine Specialists"},
    {"General Surgeons"},
    {"Urologists"},
};

string getTypeName(int t) { return tlist[t].type; }
void printList()
{
    for (int i = 0; i < tlist.size(); i++)
        cout << i + 1 << ". " << tlist[i].type << endl;
}
void printPartial(int t)
{
    for (int i = 0; i < tlist[t].did.size(); i++)
    {
        cout << "Doctor " << i + 1 << endl;
        tlist[t].did[i].printPartialDoctor();
    }
}
class patient
{
    string fname;
    string lname;
    long long int pid;
    int tid;
    jobs appointment;

public:
    string getLname()
    {
        return this->lname;
    }
    void setLname(string lname)
    {
        this->lname = lname;
    }
    string getFname()
    {
        return this->fname;
    }
    void setFname(string fname)
    {
        this->fname = fname;
    }
    void setTypeid()
    {
        int tempid;
        cout << "Enter the number corresponding to the type\n";
        printList();
        cin >> tempid;
        tid = tempid - 1;
    }
    string getTypeId() { return tlist[tid].type; }
    bool checkDoctor()
    {
        if (tlist[this->tid].did.size() != 0)
        {
            cout << "Doctors are present\n";
            return 1;
        }
        else
            cout << "No Doctor available for this type of illness\n";
        return 0;
    }
    int assignDoctor()
    {
        int range = tlist[this->tid].did.size();
        int num = rand() % range;
        this->appointment.did = tlist[tid].did[num].getDid();
        return num;
    }
    void pidGenerator()
    {
        this->pid = time(NULL);
        this->appointment.pid = this->pid;
    }
    void printAppointment()
    {
        jobs temp = this->appointment;
        cout << "Appointment" << endl;
        cout << "Job Id : " << temp.jid << endl;
        cout << "Patient Id : " << temp.pid << endl;
        cout << "Start date and time : " << ctime(&temp.start_time) << endl;
        cout << "End date and time : " << ctime(&temp.end_time) << endl;
        cout << "Appointment duration : " << temp.duration / 60 << endl;
    }
    patient()
    {
        string fname, lname;
        cout << "Enter first name : ";
        cin >> fname;
        cout << "Enter last name : ";
        cin >> lname;
        setFname(fname);
        setLname(lname);
        cout << "Enter type of doctor required";
        setTypeid();
        if (checkDoctor())
        {
            pidGenerator();
            int relnum = assignDoctor();
            this->appointment.did = tlist[this->tid].did[relnum].getDid();
            char e;
            cout << "Emergency ? (y/n)";
            cin >> e;
            if (tlist[this->tid].did[relnum].check(&this->appointment, e))
                printAppointment();
        }
    }
};

int main()
{

    bool work = true, doc;
    int n;

    while (work)
    {
        cout << "1. Create doctor\n"
             << "2.Create Patient\n"
             << "3.Print Doctor Details\n"
             << "4.Quit\n";
        cout << "Enter your choice : ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            doctor temp;
            tlist[temp.getType()].did.push_back(temp);
            break;
        }
        case 2:
        {
            patient temp;
            break;
        }

        case 3:
        {
            printList();
            cout << "\nEnter which type of doctor to be found : ";
            int t, i;
            cin >> t;
            printPartial(t - 1);
            cout << "which doctor ? ";
            cin >> i;
            tlist[t - 1].did[i - 1].PrintDoctor();
            break;
        }
        case 4:
        {
            work = false;
            break;
        }
        default:
        {
            cout << "Please enter correct choice";
            break;
        }
        }
    }
}