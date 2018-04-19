#include "Timestamp.h"

void Timestamp::setStringFormat(const std::string &format)
{
    m_format = format;
}

//------------------------------------------------------------------------------

std::string Timestamp::getStringFormat() const
{
    return m_format;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getDay() const
{
    return m_day;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getMonth() const
{
    return m_month;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getYear() const
{
    return m_year;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getHour() const
{
    return m_hour;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getMinute() const
{
    return m_minute;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getSecond() const
{
    return m_second;
}

//------------------------------------------------------------------------------

unsigned int Timestamp::getMillisecond() const
{
    return m_millisecond;
}

//------------------------------------------------------------------------------

void Timestamp::setDay(unsigned int day)
{
    if(m_day != day)
    {
        m_day = day;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setMonth(unsigned int month)
{
    if(m_month != month)
    {
        m_month = month;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setYear(unsigned int year)
{
    if(m_year != year)
    {
        m_year = year;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setHour(unsigned int hour)
{
    if(m_hour != hour)
    {
        m_hour = hour;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setMinute(unsigned int minute)
{
    if(m_minute != minute)
    {
        m_minute = minute;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setSecond(unsigned int second)
{
    if(m_second != second)
    {
        m_second = second;
    }
}

//------------------------------------------------------------------------------

void Timestamp::setMillisecond(unsigned int millisecond)
{
    if(m_millisecond != millisecond)
    {
        m_millisecond = millisecond;
    }
}

//------------------------------------------------------------------------------

std::string Timestamp::getString() const
{

    //parse format
    //TODO
    std::string tmp = "";

    std::string d = std::to_string(m_day);
    std::string m = std::to_string(m_month);
    std::string y = std::to_string(m_year);
    std::string h = std::to_string(m_hour);
    std::string minute = std::to_string(m_minute);
    std::string s = std::to_string(m_second);
    std::string mil = std::to_string(m_millisecond);

    tmp = d + "." + m + "." + y + " " + h + ":" + minute + ":" + s + ":" + mil;

    return tmp;
}

//------------------------------------------------------------------------------

bool Timestamp::operator ==(const Timestamp& rhs) const
{
    return (m_day == rhs.getDay() &&
            m_month == rhs.getMonth() &&
            m_year == rhs.getYear() &&
            m_hour == rhs.getHour() &&
            m_minute == rhs.getMinute() &&
            m_second == rhs.getSecond() &&
            m_millisecond == rhs.getMillisecond());
}

//------------------------------------------------------------------------------

bool Timestamp::operator !=(const Timestamp& rhs) const
{
    return !((*this) == rhs);
}

//------------------------------------------------------------------------------

bool Timestamp::operator <(const Timestamp& rhs) const
{
    std::pair<unsigned long, unsigned long> timeDate= mf_evaluate();
    std::pair<unsigned long, unsigned long> timeDateRhs = rhs.mf_evaluate();

    if(timeDate.first < timeDateRhs.first)
    {
        return true;
    }
    else if(timeDate.first == timeDateRhs.first)
    {
        if(timeDate.second < timeDateRhs.second)
        {
            return true;
        }
    }

    return false;
}

//------------------------------------------------------------------------------

bool Timestamp::operator >(const Timestamp& rhs) const
{
    std::pair<unsigned long, unsigned long> timeDate= mf_evaluate();
    std::pair<unsigned long, unsigned long> timeDateRhs = rhs.mf_evaluate();

    if(timeDate.first > timeDateRhs.first)
    {
        return true;
    }
    else if(timeDate.first == timeDateRhs.first)
    {
        if(timeDate.second > timeDateRhs.second)
        {
            return true;
        }
    }

    return false;
}

//------------------------------------------------------------------------------

bool Timestamp::operator <=(const Timestamp& rhs) const
{
    return !((*this) > rhs);
}

//------------------------------------------------------------------------------

bool Timestamp::operator >=(const Timestamp& rhs) const
{
    return !((*this) < rhs);
}

//------------------------------------------------------------------------------

std::pair<unsigned long, unsigned long> Timestamp::mf_evaluate() const
{
    unsigned long date = long(m_day) +
            long(32 * m_month) +
            long(385 * m_year);
    unsigned long time = long(m_millisecond) +
            long(1000*m_second) +
            long(1000*60*m_minute) +
            long(1000*60*60*m_hour);

    return std::make_pair(date,time);
}

//------------------------------------------------------------------------------
