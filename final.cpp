#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

void printList();
string getType(int);
struct jobs
{
  long long int jid = time(NULL);
  long long int pid;
  long long int did;
  time_t start_time = time(NULL);
  int duration;
  time_t end_time = time(NULL);
};

class scheduler
{
private:
  int patients = 0;
  int totaltime = 0;
  vector<jobs> today;

public:
  void setPatients() { this->patients++; }
  int getPatients() { return this->patients; }
  void setTotalTime(int duration) { this->totaltime += duration; }
  int geTotalTime() { return this->totaltime; }
  void PrintToday()
  {
    if (this->today.size() == 0)
      cout << "Doctor has no appointments\n";
    else
    {
      for (int i = 0; i < this->today.size(); i++)
      {
        jobs temp = this->today[i];
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
  void addToToday(jobs *temp)
  {
    int duration = (rand() % 21 + 10) * 60;
    if (this->today.size() == 0)
    {
      time_t now = time(NULL);
      struct tm *start = localtime(&now);
      start->tm_hour = 10;
      start->tm_min = 0;
      start->tm_sec = 0;
      temp->start_time = mktime(start);
    }
    else
      temp->start_time = this->today[this->today.size() - 1].end_time;
    temp->duration = duration;
    temp->end_time = temp->start_time + duration;
    this->today.push_back(*temp);
  }
};

class doctor
{
private:
  string fname;
  string lname;
  long long int did;
  int tid;
  scheduler schedule;

public:
  void setName(string fname, string lname)
  {
    this->fname = fname;
    this->lname = lname;
  }
  string getFname() { return this->fname; }
  string getLname() { return this->lname; }
  void setTypeid()
  {
    int tempid;
    cout << "\nTypes\n";
    printList();
    cout << "Enter the number corresponding to the type : ";
    cin >> tempid;
    tid = tempid - 1;
  }
  long long int getTypeId() { return this->tid; }
  void didGenerator() { this->did = time(NULL); }
  long long int getDid() { return this->did; }
  doctor()
  {
    string fname, lname;
    cout << "Enter first name : ";
    cin >> fname;
    cout << "Enter last name : ";
    cin >> lname;
    setName(fname, lname);
    didGenerator();
    setTypeid();
  }
  void PrintDoctor()
  {
    cout << "First name : " << getFname() << endl;
    cout << "Last name : " << getLname() << endl;
    cout << "Type : " << getType(getTypeId()) << endl;
    cout << "Doctor Id " << getDid() << endl;
    cout << "No of appointments scheduled : " << this->schedule.getPatients()
         << endl;
    cout << "Total working hours : " << (this->schedule.geTotalTime() / 60)
         << "h " << (this->schedule.geTotalTime() % 60) << "m\n";
    cout << "\nCurrent Schedule\n\n";
    this->schedule.PrintToday();
    cout << endl;
  }
  void printPartialDoctor()
  {
    cout << "First name : " << getFname() << endl;
    cout << "Last name : " << getLname() << endl;
    cout << "Doctor Id : " << getDid() << endl;
    cout << endl;
  }
  void assignJobs()
  {
    if (this->schedule.getPatients() <= 16 &&
        this->schedule.geTotalTime() <= 480)
    {
    }
    else
      cout << "Sorry, doctor is not able to take in any more appointments";
  }
  void addAppointment(jobs *temp)
  {
    this->schedule.addToToday(temp);
  }
  void printTodaySchedule() { this->schedule.PrintToday(); }
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

void printList()
{
  for (int i = 0; i < tlist.size(); i++)
    cout << i + 1 << ". " << tlist[i].type << endl;
}
string getType(int t) { return tlist[t].type; }
void printPartial(int t)
{
  for (int i = 0; i < tlist[t].did.size(); i++)
  {
    cout << "Doctor " << i + 1 << endl;
    tlist[t].did[i].printPartialDoctor();
  }
}

string getTypeName(int x) { return tlist[x - 1].type; }
class patient
{
  string fname;
  string lname;
  long long int pid;
  int tid;
  jobs appointment;

public:
  void setName(string fname, string lname)
  {
    this->lname = fname;
    this->lname = lname;
  }
  string getName() { return this->fname + this->lname; }
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
    setName(fname, lname);
    cout << "Enter type of doctor required";
    setTypeid();
    if (checkDoctor())
    {
      pidGenerator();
      int relnum = assignDoctor();
      this->appointment.did = tlist[this->tid].did[relnum].getDid();
      tlist[this->tid].did[relnum].addAppointment(&this->appointment);
       tlist[this->tid].did[relnum].assignJobs();
      cout << "Appointment booked\n";
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
      tlist[temp.getTypeId()].did.push_back(temp);
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
