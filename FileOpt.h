#ifndef __FILEOPT__
#define __FILEOPT__

class CFile {
public:
	CFile();
	~CFile();
	virtual void infile() = 0;
	virtual void outfile() = 0;
};

#endif //__FILEOPT__
