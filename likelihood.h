#ifndef __LIKELIHOOD_H__
#define __LIKELIHOOD_H__

//#define TIMING_ANALIZ
#if defined (TIMING_ANALIZ)
    static clock_t         CPUCondLikeDown;
    static clock_t         CPUScalers;
    static clock_t         CPUScalersRemove;
    static clock_t         CPUCondLikeRoot;
    static clock_t         CPULilklihood;

    #define TIME(X1,CPUtime)\
        {CPUTimeStart = clock();\
        X1;\
        CPUtime += (clock()-CPUTimeStart);}
#else
    #define TIME(X1,CPUtime)\
        X1;
#endif

#define A                           0
#define C                           1
#define G                           2
#define T                           3
#define AA                          0
#define AC                          1
#define AG                          2
#define AT                          3
#define CA                          4
#define CC                          5
#define CG                          6
#define CT                          7
#define GA                          8
#define GC                          9
#define GG                          10
#define GT                          11
#define TA                          12
#define TC                          13
#define TG                          14
#define TT                          15

CLFlt     *preLikeL;                  /* precalculated cond likes for left descendant */
CLFlt     *preLikeR;                  /* precalculated cond likes for right descendant*/
CLFlt     *preLikeA;                  /* precalculated cond likes for ancestor        */


typedef struct{
	
    CLFlt *pL;
    CLFlt *pR;

    CLFlt *clL;
    CLFlt *clR;
    CLFlt *clP;
    int  nStates;
    int *lState;
    int *rState;

	int shortCut;
    int preLikeJump;
    int k;
	int c;
	int numChars;
	int numGammaCats;
}cld_gen_prmt_t;

typedef struct{
	
    CLFlt *pL;
    CLFlt *pR;
	CLFlt *pA;
    CLFlt *clL;
    CLFlt *clR;
    CLFlt *clP;
	CLFlt *clA;
    int   nStates;
    int *lState;
    int *rState;
	int *aState;
	int shortCut;
    int preLikeJump;
    int k;
	int c;
	int numChars;
	int numGammaCats;
}clr_gen_prmt_t;

typedef struct{
	
    CLFlt **clP;
    int   nStates;
	int c;
	int numChars;
	int numGammaCats;
	CLFlt *scP;
	CLFlt *lnScaler;
    CLFlt *clPtr;
    CLFlt scaler;
}cls_gen_prmt_t;

typedef struct{
	CLFlt **clP;
	CLFlt *clPtr;
	CLFlt *lnScaler;
	CLFlt *nSitesOfPat;
	CLFlt *clInvar;
	MrBFlt lnL;
	MrBFlt freq;
	MrBFlt *bs;
	MrBFlt pInvar;
	int hasPInvar;
	int numChars;
	int numGammaCats;
	int nStates;
	int c;
}likeh_gen_prmt_t;

typedef struct{
	CLFlt *pL;
	CLFlt *pR;
	CLFlt *clL;
	CLFlt *clR;
	CLFlt *clP;
	
	int *lState;
	int *rState;
	
	int shortCut;
	int k;
	int c;
	int h;
	int numChars;
	int numGammaCats;	
}cld_nuc4_prmt_t;

typedef struct{
	CLFlt *pL;
	CLFlt *pR;
	CLFlt *pA;
	CLFlt *clL;
	CLFlt *clR;
	CLFlt *clP;
	CLFlt *clA;
	
	int *lState;
	int *rState;
	int *aState;
	
	int shortCut;
	int k;
	int c;
	int h;
	int numChars;
	int numGammaCats;		
}clr_nuc4_prmt_t;

typedef struct{
	CLFlt **clP;
	int c;
	int numChars;
	int numGammaCats;
	CLFlt *scP;
	CLFlt *lnScaler;
    CLFlt *clPtr;
    CLFlt scaler;
	
}cls_nuc4_prmt_t;

typedef struct{
	CLFlt **clP;
	int c;
	int numChars;
	int numGammaCats;
	CLFlt *clPtr;
	CLFlt *scP;
	CLFlt *lnScaler;
	CLFlt *nSitesOfPat;
	CLFlt *clInvar;
	MrBFlt lnL;
	MrBFlt freq;
	MrBFlt *bs;
	MrBFlt pInvar;
	int hasPInvar;
}likeh_nuc4_prmt_t;
#ifdef AVX_ENABLED
typedef struct{
	CLFlt *pL;
	CLFlt *pR;
	__m256 *clL;
	__m256 *clR;
	__m256 *clP;
	int numAVXChars;	
	int numGammaCats;
	int c;
}cld_nuc4_AVX_prmt_t;

typedef struct{
	CLFlt *pL;
	CLFlt *pR;
	CLFlt *pA;
	__m256 *clL;
	__m256 *clR;
	__m256 *clA;
	__m256 *clP;
	int numAVXChars;
	int numGammaCats;
	int c;
}clr_nuc4_AVX_prmt_t;

typedef struct{
	CLFlt *scP;
	CLFlt *lnScaler;
	__m256          *clPtr, **clP, *scP_AVX, *lnScaler_AVX;
	int numAVXChars;
	int numGammaCats;
	int c;
	int c1;
}cls_nuc4_AVX_prmt_t;

typedef struct{
	
    CLFlt *pL;
    CLFlt *pR;

    __m256 *clL;
    __m256 *clR;
    __m256 *clP;
    int  nStates;
    int *lState;
    int *rState;

	int shortCut;
    int preLikeJump;
	int c;
	int numAVXChars;
	int numGammaCats;
}cld_gen_AVX_prmt_t;


typedef struct{
	
    CLFlt *pL;
    CLFlt *pR;
	CLFlt *pA;

    __m256 *clL;
    __m256 *clR;
    __m256 *clP;
	__m256 *clA;
    int  nStates;
    int *lState;
    int *rState;
	int *aState;

	int shortCut;
    int preLikeJump;
	int c;
	int numAVXChars;
	int numGammaCats;
}clr_gen_AVX_prmt_t;

typedef struct{
	CLFlt *scP;
	CLFlt *lnScaler;
	__m256          *clPtr, **clP, *scP_AVX, *lnScaler_AVX;
	int numAVXChars;
	int numGammaCats;
	int c;
	int c1;
	int nStates;
}cls_gen_AVX_prmt_t;

#endif

int       CondLikeDown_Bin (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeDown_Bin_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeDown_Bin_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeDown_Gen (TreeNode *p, int division, int chain);

#if defined  (FINE_GRAINED)
void       ThreadCLDown_Gen (int id);
void       ThreadCLRoot_Gen (int id);
void       ThreadCLScaler_Gen (int id);
void       ThreadLikeH_Gen (int id);
void       *ThreadCLMix_Gen(void *prmt);

void       ThreadCLDown_NUC4 (int id);
void       ThreadCLRoot_NUC4 (int id);
void       ThreadCLScaler_NUC4 (int id);
void       ThreadLikeH_NUC4 (int id);
void       *ThreadCLMix_NUC4 (void *prmt);
#endif

#if defined (SSE_ENABLED)
int       CondLikeDown_Gen_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeDown_Gen_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeDown_Gen_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeDown_NUC4 (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeDown_NUC4_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeDown_NUC4_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeDown_NUC4_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeDown_NY98 (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeDown_NY98_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeDown_NY98_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeDown_Std (TreeNode *p, int division, int chain);
int       CondLikeRoot_Bin (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeRoot_Bin_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeRoot_Bin_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeRoot_Gen (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeRoot_Gen_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeRoot_Gen_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeRoot_Gen_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeRoot_NUC4 (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeRoot_NUC4_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeRoot_NUC4_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeRoot_NUC4_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeRoot_NY98 (TreeNode *p, int division, int chain);

#if defined (SSE_ENABLED)
int       CondLikeRoot_NY98_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeRoot_NY98_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeRoot_Std (TreeNode *p, int division, int chain);
int       CondLikeScaler_Gen (TreeNode *p, int division, int chain);

#if defined (SSE_ENABLED)
int       CondLikeScaler_Gen_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeScaler_Gen_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeScaler_Gen_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeScaler_NUC4 (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeScaler_NUC4_SSE (TreeNode *p, int division, int chain);
#endif
#if defined (AVX_ENABLED)
int       CondLikeScaler_NUC4_AVX (TreeNode *p, int division, int chain);
#endif
int       CondLikeScaler_NUC4_GibbsGamma (TreeNode *p, int division, int chain);
int       CondLikeScaler_NY98 (TreeNode *p, int division, int chain);
#if defined (SSE_ENABLED)
int       CondLikeScaler_NY98_SSE (TreeNode *p, int division, int chain);
#endif

#if defined (AVX_ENABLED)
int       CondLikeScaler_NY98_AVX (TreeNode *p, int division, int chain);
#endif

int       CondLikeScaler_Std (TreeNode *p, int division, int chain);
int       CondLikeUp_Bin (TreeNode *p, int division, int chain);
int       CondLikeUp_Gen (TreeNode *p, int division, int chain);
int       CondLikeUp_NUC4 (TreeNode *p, int division, int chain);
int       CondLikeUp_Std (TreeNode *p, int division, int chain);
void      LaunchLogLikeForDivision (int chain, int d, MrBFlt* lnL);
int       Likelihood_Adgamma (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       Likelihood_Gen (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#if defined (SSE_ENABLED)
int       Likelihood_Gen_SSE (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
#if defined (AVX_ENABLED)
int       Likelihood_Gen_AVX (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
int       Likelihood_Gen_GibbsGamma (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       Likelihood_NUC4 (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#if defined (SSE_ENABLED)
int       Likelihood_NUC4_SSE (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
#if defined (AVX_ENABLED)
int       Likelihood_NUC4_AVX (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
int       Likelihood_NUC4_GibbsGamma (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       Likelihood_NY98 (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#if defined (SSE_ENABLED)
int       Likelihood_NY98_SSE (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
#if defined (AVX_ENABLED)
int       Likelihood_NY98_AVX (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
int       Likelihood_Pars (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       Likelihood_ParsStd (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       Likelihood_Res (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#if defined (SSE_ENABLED)
int       Likelihood_Res_SSE (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif
#if defined (AVX_ENABLED)
int       Likelihood_Res_AVX (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
#endif


int       Likelihood_Std (TreeNode *p, int division, int chain, MrBFlt *lnL, int whichSitePats);
int       TiProbs_Fels (TreeNode *p, int division, int chain);
int       TiProbs_Gen (TreeNode *p, int division, int chain);
#ifdef AVX_ENABLED
int       TiProbs_Gen_AVX (TreeNode *p, int division, int chain);
#endif
int       TiProbs_GenCov (TreeNode *p, int division, int chain);
int       TiProbs_Hky (TreeNode *p, int division, int chain);
int       TiProbs_JukesCantor (TreeNode *p, int division, int chain);
int       TiProbs_Std (TreeNode *p, int division, int chain);
int       TiProbs_Res (TreeNode *p, int division, int chain);

#ifdef FINE_GRAINED
#define NUM_THREADS 4
#define CLDOWN 1
#define CLROOT 2
#define CLSCALER 3
#define LIKEH 4

#define GEN 1
#define NUC4 2

int             charNum[NUM_THREADS];


pthread_t       clmix_gen_thd[NUM_THREADS];
int             clmix_gen_id[NUM_THREADS];
cld_gen_prmt_t cld_gen_prmt[NUM_THREADS];
clr_gen_prmt_t clr_gen_prmt[NUM_THREADS];
cls_gen_prmt_t cls_gen_prmt[NUM_THREADS];
likeh_gen_prmt_t likeh_gen_prmt[NUM_THREADS];

pthread_t       clmix_nuc4_thd[NUM_THREADS];
int             clmix_nuc4_id[NUM_THREADS];
cld_nuc4_prmt_t cld_nuc4_prmt[NUM_THREADS];
clr_nuc4_prmt_t clr_nuc4_prmt[NUM_THREADS];
cls_nuc4_prmt_t cls_nuc4_prmt[NUM_THREADS];
likeh_nuc4_prmt_t likeh_nuc4_prmt[NUM_THREADS];

pthread_barrier_t start_barrier;
pthread_barrier_t stop_barrier;
pthread_barrier_t half_barrier;

#if defined (AVX_ENABLED)
cld_nuc4_AVX_prmt_t cld_nuc4_AVX_prmt[NUM_THREADS];
clr_nuc4_AVX_prmt_t clr_nuc4_AVX_prmt[NUM_THREADS];
cls_nuc4_AVX_prmt_t cls_nuc4_AVX_prmt[NUM_THREADS];
int				charNumScaler[NUM_THREADS];
int ThreadCLDown_NUC4_AVX (int id);
int ThreadCLRoot_NUC4_AVX (int id);
int ThreadCLScaler_NUC4_AVX (int id);
pthread_t       clmix_nuc4_AVX_thd[NUM_THREADS];
void       *ThreadCLMix_NUC4_AVX(void *prmt);

cld_gen_AVX_prmt_t cld_gen_AVX_prmt[NUM_THREADS];
clr_gen_AVX_prmt_t clr_gen_AVX_prmt[NUM_THREADS];
cls_gen_AVX_prmt_t cls_gen_AVX_prmt[NUM_THREADS];
int ThreadCLDown_Gen_AVX(int id);
int ThreadCLRoot_Gen_AVX(int id);
int ThreadCLScaler_Gen_AVX(int id);
pthread_t       clmix_gen_AVX_thd[NUM_THREADS];
void       *ThreadCLMix_Gen_AVX(void *prmt);

#endif

#endif


#endif  /* __LIKELIHOOD_H__ */
