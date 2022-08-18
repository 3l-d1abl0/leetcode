class Solution {
public:
    
    
    int searchPatternRabinKarp(string &str, string &pat){
        
        int strlen = str.size();
        int patlen = pat.size();

        int b= 256;
        int Q= 9973;	//prime

        //1. Calculate the pow
        int pow = 1;//pow(b, patlen-1)
        for(int i=1; i<patlen; i++)
            pow = (pow*b)%Q;

        //2. calculate the hash of first patlen
        int ph =0, sh=0;
        for(int i=0; i<patlen; i++){

            ph = (ph*b + (pat[i]-'A'+1))%Q;
            sh = (sh*b + (str[i]-'A'+1))%Q;
        }

        
        //3. loop through the string
        for(int i=0; i<=strlen-patlen; i++){

            //cout<<i<<" "<<sh<<endl;
            if(ph==sh){

                /* Also check via individual character matching in case of collision */
                int j;
                for(j=0; j<patlen; j++){
                    if(pat[j]!=str[i+j])
                        break;
                }
                //whole string matched
                if(j==patlen)
                    return i;
            }

            //there is not next character if we have reached the last pos
            if(i<strlen-patlen){
                sh = (( sh- ((str[i]-'A'+1)*pow)%Q )*b + (str[i+patlen]-'A'+1)) %Q;

                //if hash becomes negative make it POS
                if(sh<=0)
                    sh+=Q;
            }

        }


        return -1;
        
    }
    
    void buildLPS(string &str, vector<int> &LPS){

        LPS[0] =0;
        int len =0, idx=1;


        while(idx<str.size()){

            if(str[idx]==str[len]){
                LPS[idx] = len+1;
                len++;
                idx++;
            }else{

                if(len==0){
                    LPS[idx] = 0;
                    idx++;
                }else{
                    len = LPS[len-1];
                }
            }

        }//while

    }

    
    int searchPatternKMP(string &str, string &pat){
        
        int strlen = str.size();
        int patlen = pat.size();

        vector<int> LPS(patlen);

        buildLPS(pat, LPS);

        //LPS Array ready, lets match
        int sidx =0, pidx =0;
        vector<int> pos;

        while(sidx<strlen){

            if(str[sidx]==pat[pidx]){

                sidx++;
                pidx++;

                if(pidx==patlen){
                    //cout<<"at "<<sidx-patlen<<" "<<str.substr(sidx-patlen, patlen)<<endl;
                    return sidx-patlen;
                    
                }
            }else{

                if(pidx==0)
                    sidx++;
                else
                    pidx = LPS[pidx-1];

            }

        }//while


        return -1;
        
    }
    
    int strStr(string str, string pat) {
        
        
        //1.Rabin Karp
        //return searchPatternRabinKarp(str, pat);
        
        //2.KMP
        return searchPatternKMP(str, pat);
        
        
    }
};