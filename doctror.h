#ifndef DOCTOR_H
#define DOCTOR_H
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
  void setType(int temp)
  {
    this->type = type;
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

#endif