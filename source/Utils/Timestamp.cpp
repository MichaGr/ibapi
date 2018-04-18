#include "Timestamp.h"

void Timestamp::setStringFormat(const std::string &format)
{
    m_format = format;
}

std::string Timestamp::getStringFormat() const
{
    return m_format;
}

unsigned int Timestamp::getDay() const
{
    return m_day;
}

unsigned int Timestamp::getMonth() const
{
    return m_month;
}

unsigned int Timestamp::getYear() const
{
    return m_year;
}

void Timestamp::setDay(unsigned int day)
{
    if(m_day != day)
    {
        m_day = day;
    }
}

void Timestamp::setMonth(unsigned int month)
{
    if(m_month != month)
    {
        m_month = month;
    }
}

void Timestamp::setYear(unsigned int year)
{
    if(m_year != year)
    {
        m_year = year;
    }
}

std::string Timestamp::getString() const
{

    //parse format
    //TODO
    std::string tmp = "";

    std::string d = std::to_string(m_day);
    std::string m = std::to_string(m_month);
    std::string y = std::to_string(m_year);

    tmp = d + "." + m + "." + y;

    return tmp;
}

bool Timestamp::operator ==(const Timestamp& rhs) const
{
    return (m_day == rhs.getDay() && m_month == rhs.getMonth() && m_year == rhs.getYear());
}

bool Timestamp::operator !=(const Timestamp& rhs) const
{
    return (m_day != rhs.getDay() || m_month != rhs.getMonth() || m_year != rhs.getYear());
}

bool Timestamp::operator <(const Timestamp& rhs) const
{
    return _evaluate() < rhs._evaluate();
}

bool Timestamp::operator >(const Timestamp& rhs) const
{
    return _evaluate() > rhs._evaluate();
}

bool Timestamp::operator <=(const Timestamp& rhs) const
{
    return _evaluate() <= rhs._evaluate();
}

bool Timestamp::operator >=(const Timestamp& rhs) const
{
    return _evaluate() >= rhs._evaluate();
}

unsigned int Timestamp::_evaluate() const
{
    return (m_day + 32u * m_month + 385u * m_year);
}
