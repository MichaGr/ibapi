#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>

class Timestamp
{
public:
    Timestamp() :
        m_day(0),
        m_month(0),
        m_year(0)
    {}

    Timestamp(unsigned int day,unsigned int month,unsigned int year) :
        m_day(day),
        m_month(month),
        m_year(year)
    {}

    void setStringFormat(const std::string& format);
    std::string getStringFormat() const;

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    std::string getString() const;

    bool operator ==(const Timestamp& rhs) const;
    bool operator !=(const Timestamp& rhs) const;
    bool operator < (const Timestamp& rhs) const;
    bool operator > (const Timestamp& rhs) const;
    bool operator <=(const Timestamp& rhs) const;
    bool operator >=(const Timestamp& rhs) const;

protected:

    unsigned int _evaluate() const;

private:


    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

    std::string  m_format;
};

#endif // TIMESTAMP_H
