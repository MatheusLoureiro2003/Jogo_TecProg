#pragma once
#include "Ente.h"

class Estado :
    public Ente
{
private:
    bool remove;
public:
    Estado(const IDs ID);
    virtual ~Estado();
    virtual void executar() = 0;
    virtual void draw();
    void setRemove(const bool remover = true);
    const bool getRemove() const;
    //virtual void mudarEstadoObservador() = 0;
};


