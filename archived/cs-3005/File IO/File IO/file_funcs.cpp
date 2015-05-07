#include "file_funcs.h"


std::vector<std::string> read_words(const char *filename)
{
    std::vector<std::string> words;
    std::ifstream fin(filename);
    if(!fin)
    {
      std::cerr << "Could not open " << filename << std::endl;
    }

    std::string tmp;
    while(fin)
    {
      fin >> tmp;
      if(fin)
        {
          words.push_back(tmp);
        }
    }
    fin.close();
    return words;
}

bool write_words(const char *filename, std::vector<std::string> words)
{
    std::ofstream fout(filename);
    if(!fout)
    {
      std::cerr << "Unable to open " << filename << std::endl;
      return false;
    }

    /* one item per line */
    int i;
    int size = int(words.size());
    for(i = 0; i < size; i++)
    {
      fout << words[i] << std::endl;
    }

    fout.close();
    return true;
}

bool copy_file(const char *ifilename, const char *ofilename)
{
    std::vector<std::string> input = read_words(ifilename);

    bool pass = write_words(ofilename, input);
    if(!pass)
    {
        return false;
    }
    return true;
}
