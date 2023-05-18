#include"iostream"
using namespace std;

#include<string>
#include"BinTree.h"
#define HuffTree BinTree<HaffChar>
#define N_CHAR （0x80 - 0x20)

struct HuffChar {
	char ch; //字符 
	int weight; //频率
	HuffChar ( char c = '^', int w = 0): ch(c), weight (w) {
	} ;
	
	bool operator< (HuffChar const& hc) {
		return weight < hc.weight;
	}
	bool operator> (HaffChar const& hc) {
		return weight > hc.weight;
	}
	bool operator== ( HuffChar const& hc) {
		return weight == hc.weight;
	}
}; 


void memset(int* freq){
	for(int i=0; i<N_CHAR;i++) {
		freq[i] = 0;
	}
}

void release (int *freq ){
	delete freq[];
}



int* statistics ( char* sample_file ) {
	int* freq = new int[N_CHAR];
	memset( freq);//清零 
	FILE* fp = fopen ( sample_file , "r"); //打开文件
	for( char ch; 0 < fscanf ( fp, "%c", &ch);){
		if (ch >= 0x20 ) freq[ch- 0x20 ]++;//累计次数 
	} 
	fclose(fp);
	return freq;
} 

class HuffForest:{
private:
	HUffChar* forest[N_CHAR];
public:

	HuffForest(int* freq ){
		for(int i=0;i<N_CHAR;i++){
			forest[i] = new HuffTree;
			forest[i]->insertAsRoot( HUffChar(0x20+i,freq[i] ) );
		}
	}
};

HuffTree* minHChar ( HuffForest* forest){ //权重最小 
	int rmin = 0;
	int minweight = forest[min].weight;
	for(int i=0;i<N_CHAR;i++){
		if(minforest > forest[i].weight){
			min = i;
			minforest = forest[i].weight;
		}
		return BinTree.remove(()forest[min]);
	}
}

HuffTree* generateTree ( Huffforest* forest)
{
	while(fores->size(>1)){
		HuffTree* T1 = minHChar (forest);
		HuffTree* T2 = CminHChar(forest);
		HuffTree* S = new HuffTree;
		S->insertAsRoot(HuffChar("^",T1.weight+T2.weight);
		 
	}
}

int main( int argc, char* argv[] )
{
	*argv = "IHAD.txt"; 
	int* freq = statistics ( argv[1] ); //根据样本文件，统计各字符出现频率
	HuffForest forest(freq);
	release( freq ); //创建树林 
	HuffTree* tree = generateTree ( forest ); release( forest );
	
	for( int i=2;i<argc;i++){//对每一串传入的
		int n = encode ( table, codestring, argv[i] );
		decode ( tree, codeString, n);
		release( codeString); 
	}
	relsease(table);release(tree);
	return 0;
	
	
}
