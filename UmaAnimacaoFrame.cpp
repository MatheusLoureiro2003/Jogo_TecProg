#include "UmaAnimacaoFrame.h"

UmaAnimacaoFrame::UmaAnimacaoFrame() :texture(nullptr)
{
}

UmaAnimacaoFrame::~UmaAnimacaoFrame()
{
}

void UmaAnimacaoFrame::initialize(const char* path)
{
	texture = pGG->loadTexture(path);
}
