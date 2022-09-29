
#include "wave/wavreader.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[])
{
  void* h_x = wav_read_open("/Users/zyc/code/C/loadwav/samples/p225_002.wav"); // 绝对路径

  int format, channels, sr, bits_per_sample;
  unsigned int data_length;
  int res = wav_get_header(h_x, &format, &channels, &sr, &bits_per_sample, &data_length);
  if (!res)
  {
    cerr << "get ref header error: " << res << endl;
    return -1;
  }
  int samples = data_length * 8 / bits_per_sample; // audio  data  length
  std::vector<int16_t> tmp(samples);
  res = wav_read_data(h_x, reinterpret_cast<unsigned char*>(tmp.data()), data_length);
  wav_read_close(h_x);
  if (res < 0)
  {
    cerr << "read wav file error: " << res << endl;
    return -1;
  }
  std::vector<float> x(samples);
  for (int i = 0; i < tmp.size(); ++i) {
      x[i] = (float)tmp[i] /32767.f;
  }

  std::cout << "data value: " << x[64938]  << std::endl;
  std::cout << "Sample rate: " << sr << "Hz" << std::endl;

  int n_fft = 400;
  int n_hop = 160;
  int n_mel = 40;
  int fmin = 80;
  int fmax = 7600;



  return 0;
}

