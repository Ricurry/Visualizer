#ifndef FFT_CLASS_H
#define FFT_CLASS_H
#include "../aquila/aquila/global.h"
#include "../aquila/aquila/tools/TextPlot.h"
#include "../aquila/aquila/source/WaveFile.h"
#include "../aquila/aquila/source/generator/SineGenerator.h"
#include "../aquila/aquila/transform/FftFactory.h"
class ffm 
{
  public:

    Aquila::SpectrumType  FFT();
};



#endif

