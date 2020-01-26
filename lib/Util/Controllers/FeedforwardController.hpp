//
// Created by emdash00 on 8/3/19.
//

#ifndef ARDUINO_TEMPLATE_FEEDFORWARDCONTROLLER_HPP
#define ARDUINO_TEMPLATE_FEEDFORWARDCONTROLLER_HPP


class FeedforwardController
{
public:
     explicit FeedforwardController(const double proportion, const double offset)
     : m_proportion(proportion), m_offset(offset) { }
     double Calculate(double);

private:
    const double m_proportion, m_offset;

};


#endif //ARDUINO_TEMPLATE_FEEDFORWARDCONTROLLER_HPP
