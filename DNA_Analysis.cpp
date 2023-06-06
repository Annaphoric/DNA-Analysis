//DNA transcription & translation

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, char> aminoAcids {{"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'}, {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'}, {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '|'}, {"UAG", '|'}, {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '|'}, {"UGG", 'W'}, {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'}, {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'}, {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'}, {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'}, {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'}, {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'}, {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'}, {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'}, {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'}, {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'}, {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'}, {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}};

int check(string DNA);
string complementary(string DNA);
void countNucleotides(string DNA, int *nucleotides);
string transcribe(string DNA);
string translate(string RNA);

int main(int argc, char* argv[]) {
	string DNAstrand, RNAstrand, protein;
	int A, T, C, G;
	int nucleotides[4]; int percentages[4];
	while(1) {
		A = 0; T = 0; C = 0; G = 0;
		for(short k = 0; k < 4; k++) {
			nucleotides[k] = 0;
		}
		for(int i = 0; i < 100; i++) {
			cout << '_';
		}
		cout << "\n\n\n~~~NEW DNA ANALYSIS~~~\n\n\nEnter DNA strand: ";
		cin >> DNAstrand;
		
		if(check(DNAstrand) == 0) {
			cout << "\nThis DNA strand contains an abnormal nucleotide base and cannot be read.\n\n\n\n" << endl;
			continue;
		}
		
		cout << "\nLength of DNA is " << DNAstrand.length() << " nucleotides." << endl;
		
		for(int i = 0; i < DNAstrand.length(); i++) {
			if(DNAstrand[i] == 'A') A++;
			else if(DNAstrand[i] == 'T') T++;
			else if(DNAstrand[i] == 'C') C++;
			else G++;
	}
		nucleotides[0] = A; percentages[0] = (A * 100) / DNAstrand.length();
		nucleotides[1] = T; percentages[1] = (T * 100) / DNAstrand.length();
		nucleotides[2] = C; percentages[2] = (C * 100) / DNAstrand.length();
		nucleotides[3] = G; percentages[3] = (G * 100) / DNAstrand.length();
		
		cout << "\n\nAmounts of each nucleotide: \n\nA\tT\tC\tG\n";
		for(int i = 0; i < 30; i++) {
			cout << '-';
		}
		cout << "\n";
		for(short i = 0; i < 4; i++) {
			cout << nucleotides[i] << "\t";
		}
		cout << "\n";
		for(short i = 0; i < 4; i++) {
			cout <<  '(' << percentages[i] << "%)\t";
		}
		cout << "\n";
		for(int i = 0; i < 30; i++) {
			cout << '-';
		}
		
		cout << "\n\n\nDepiction of double-stranded DNA: \n\n" << DNAstrand << endl;
		cout << complementary(DNAstrand) << endl;
		
		RNAstrand = transcribe(DNAstrand);
		cout << "\n\n\nCorresponding RNA strand: \n\n" << RNAstrand << "\n\n" << endl;
	
		protein = translate(RNAstrand);
		cout << "\nCorresponding protein: \n\n" << protein << "\n\n" << endl;
		cout << "\nLength of protein is " << protein.length() << " amino acids." << endl;
		
		cout << "\n\n\n~~~END OF ANALYSIS~~~\n\n\n\n\n";
	}
}

int check(string DNA) {
	int normal = 0;
	for(int i = 0; i < DNA.length(); i++) {
		if(DNA[i] == 'A' || DNA[i] == 'T' || DNA[i] == 'C' || DNA[i] == 'G') normal = 1;
		else {normal = 0; break;}
	}
	return(normal);
}

string complementary(string DNA) {
	string compDNAstrand;
	for(int i = 0; i < DNA.length(); i++) {
		if(DNA[i] == 'A') compDNAstrand += 'T';
		else if(DNA[i] == 'T') compDNAstrand += 'A';
		else if(DNA[i] == 'G') compDNAstrand += 'C';
		else compDNAstrand += 'G';
	}
	return(compDNAstrand);
}

string transcribe(string DNA) {
	string RNA;
	for(int i = 0; i < DNA.length(); i++) {
		if(DNA[i] == 'A') RNA += 'U';
		else if(DNA[i] == 'T') RNA += 'A';
		else if(DNA[i] == 'G') RNA += 'C';
		else RNA += 'G';
	}
	return(RNA);
}

string translate(string RNA) {
	string codon, protein;
	for(int i = 0; i < RNA.length(); i++) {
		codon += RNA[i];
		if(i % 3 == 2) {
			protein += aminoAcids[codon];
			codon = "";
		}
	}
	return(protein);
}
