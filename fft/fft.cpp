#include "fft.h"
Aquila::SpectrumType ffm::FFT() 
{
    // WAV file.
    Aquila::WaveFile mywav("sound.wav");
    // input signal parameters
    const std::size_t SIZE = 52117000;
    const Aquila::FrequencyType sampleFreq = mywav.getSampleFrequency();
    const Aquila::FrequencyType f1 = 125, f2 = 700;

    Aquila::SineGenerator sineGenerator1 = Aquila::SineGenerator(sampleFreq);
    sineGenerator1.setAmplitude(32).setFrequency(f1).generate(SIZE);
    Aquila::SineGenerator sineGenerator2 = Aquila::SineGenerator(sampleFreq);
    sineGenerator2.setAmplitude(8).setFrequency(f2).setPhase(0.75).generate(SIZE);
    auto sum = sineGenerator1 + sineGenerator2;

    auto fft = Aquila::FftFactory::getFft(SIZE);
    Aquila::SpectrumType spectrum = fft->fft(sum.toArray());
    return spectrum;
}
