#ifndef AUDIO_H
#define AUDIO_H

#include <vector>
#include <iostream>
#include <fstream>

class Wav
{
public:
    Wav(void);
    ~Wav(void) {}

    bool loadFromWav(std::string filename);
    void loadFromVector(const std::vector<std::int16_t>& data, int sampleRate, int numChannel);

    bool saveToWav(std::string filename) const;

    int getSampleRate(void) const;
    int getNumChannel(void) const;

    const std::vector<std::int16_t>& getData(void) const;
private:

    int mSampleRate;
    int mNumChannel;

    std::vector<std::int16_t> mData;


    template <class T>
    static void write(std::ofstream& ofs,const T& data)
    {
        ofs.write( (char*)&data , sizeof(T));
    }

    template <class T>
    static T read(std::ifstream& ifs)
    {
        char* data = new char[sizeof(T)];

        ifs.read(data,sizeof(T));

        const T result = *(T*)data;

        delete data;

        return result;
    }

    static std::string extractStr(std::ifstream& ifs, const int size);
    static void encodeStr(std::ofstream& ofs, const std::string& str);
};

#endif // AUDIO_H
