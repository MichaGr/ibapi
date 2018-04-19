#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>
#include <utility>

class Timestamp
{
public:

    Timestamp(unsigned int year = 0,
              unsigned int month = 0,
              unsigned int day = 0,
              unsigned int hour = 0,
              unsigned int minute = 0,
              unsigned int second = 0,
              unsigned int millisecond = 0) :
        m_year(year),
        m_month(month),
        m_day(day),
        m_hour(hour),
        m_minute(minute),
        m_second(second),
        m_millisecond(millisecond)
    {}

    void setStringFormat(const std::string& format);
    std::string getStringFormat() const;

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;
    unsigned int getMillisecond() const;

    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);
    void setHour(unsigned int hour);
    void setMinute(unsigned int minute);
    void setSecond(unsigned int second);
    void setMillisecond(unsigned int millisecond);

    std::string getString() const;

    bool operator ==(const Timestamp& rhs) const;
    bool operator !=(const Timestamp& rhs) const;
    bool operator < (const Timestamp& rhs) const;
    bool operator > (const Timestamp& rhs) const;
    bool operator <=(const Timestamp& rhs) const;
    bool operator >=(const Timestamp& rhs) const;

protected:

    std::pair<unsigned long,unsigned long> mf_evaluate() const;

private:


    unsigned int m_year;
    unsigned int m_month;
    unsigned int m_day;
    unsigned int m_hour;
    unsigned int m_minute;
    unsigned int m_second;
    unsigned int m_millisecond;

    std::string  m_format;
};

#endif // TIMESTAMP_H
