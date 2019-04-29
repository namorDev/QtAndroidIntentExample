#ifndef INTENT_H
#define INTENT_H

class QString;

class Intent
{
public:
    Intent();
    void send(const QString& extraMessage);
};

#endif // INTENT_H
