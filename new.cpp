#include <bits/stdc++.h>
using namespace std;
void printList();
struct appointments
{
  long long int pid;
  long long int did;
  long long int jid;
  time_t start_time;
  time_t end_time;
  int duration;
};
class doctor
{
private:
  string fname;
  string lname;
  long long int id;
  int type;
  int patients = 0;
  int working_hours = 0;
  vector<appointments> appointment;

public:
  string getFname()
  {
    return this->fname;
  }

  void setFname(string fname)
  {
    this->fname = fname;
  }

  string getLname()
  {
    return this->lname;
  }

  void setLname(string lname)
  {
    this->lname = lname;
  }

  long long int getId()
  {
    return this->id;
  }

  void setId()
  {
    this->id = time(NULL);
  }
  int getType()
  {
    return this->type;
  }
  void setType()
  {
    printList();
    int x;
    cin >> x;
    this->type = x - 1;
  }

  int getPatients()
  {
    return this->patients;
  }

  void setPatients()
  {
    this->patients++;
  }

  int getWorking_hours()
  {
    return this->working_hours;
  }

  void setWorking_hours(int working_hours)
  {
    this->working_hours = working_hours;
  }
  void addWorking_hours(int working_hours)
  {
    this->working_hours += working_hours;
  }

  void addAppointments(appointments temp)
  {
    if (getPatients() < 16 && (getWorking_hours() + temp.duration <= 480))
    {
      setPatients();
      setWorking_hours(temp.duration);
      this->appointment.push_back(temp);
    }
  }
  void setAppointments(vector<appointments> appointments)
  {
    this->appointment = appointments;
  }
  void printAppointments()
  {
    for (int i = 0; i < this->appointment.size(); i++)
    {
      appointments temp = this->appointment[i];
      cout << "Appointment : " << i + 1 << endl;
      cout << "Job Id : " << temp.jid << endl;
      cout << "Patient Id : " << temp.pid << endl;
      cout << "Start date and time : " << localtime(&temp.start_time) << endl;
      cout << "End date and time : " << localtime(&temp.end_time) << endl;
      cout << "Appointment duration : " << temp.duration << endl;
    }
  }
  time_t getEarliestFreeTime()
  {
    if (this->appointment.size() > 0)
      return this->appointment[this->appointment.size()].end_time;
    else
    {
      time_t st = time(NULL);
      struct tm *start_time = localtime(&st);
      start_time->tm_hour = 10;
      start_time->tm_min = 0;
      start_time->tm_sec = 0;
      st = mktime(start_time);
      return st;
    }
  }
  doctor()
  {
    string fname, lname;
    cout << "Enter your first name";
    cin >> fname;
    setFname(fname);
    cout << "Enter your last name";
    cin >> fname;
    setLname(lname);
    setId();
  }
};
class patient
{
private:
  string fname;
  string lname;
  long long int id;
  int type;
  appointments appointment;

public:
  string getFname()
  {
    return this->fname;
  }

  void setFname(string fname)
  {
    this->fname = fname;
  }

  string getLname()
  {
    return this->lname;
  }

  void setLname(string lname)
  {
    this->lname = lname;
  }

  long long int getId()
  {
    return this->id;
  }

  void setId()
  {
    this->id = time(NULL);
  }
  int getType()
  {
    return this->type;
  }
  void setType()
  {
    printList();
    int x;
    cin >> x;
    this->type = x - 1;
  }
  bool checkDoctor()
  {
    if (tlist[this->type].did.size() != 0)
      return 1;
    return 0;
  }
  void setAppointment(doctor dtemp)
  {
    time_t start_time = dtemp.getEarliestFreeTime();
    cout << "Doctor is earliest free at " << localtime(&start_time);
    this->appointment.start_time = start_time;
    this->id = this->appointment.pid;
    this->appointment.did = dtemp.getId();
    getDuration();
    dtemp.addAppointments(this->appointment);
  }
  void getDuration()
  {
    int random = 10 + (rand() % 30);
    this->appointment.duration = random;
    this->appointment.end_time = this->appointment.start_time + random * 60;
  }
  void appointDoctor()
  {
    int range = tlist[this->type].did.size();
    
  }
  patient(doctor temp)
  {
    string fname, lname;
    cout << "Enter your first name";
    cin >> fname;
    setFname(fname);
    cout << "Enter your last name";
    cin >> fname;
    setLname(lname);
    setType();
    setId();
    if (checkDoctor())
    {
      cout << "Doctors are available\n";
      setAppointment(temp);
    }
    else
      cout << "Sorry there are no doctors of this kind present at the moment\n";
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
void printList()
{
  for (int i = 1; i <= tlist.size(); i++)
  {
    cout << i - 1 << ". " << tlist[i].type;
  }
}
int main()
{
  // doctor d1;
  // patient p1(d1);
  bool work = true, doc;
  int n;

  while (work)
  {
    cout << "1. Create doctor\n"
         << "2.Create Patient\n";
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
      patient ptemp(temp);
    }
    case 3:
    {
      work = false;
    }
    default:
    {
      cout << "Please enter correct choice";
      break;
    }
    }
  }
}