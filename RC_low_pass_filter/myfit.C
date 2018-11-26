#include "RC_data.h"


//this ROOT macro uses the data stored in "RC_data.dat"
//to confirm the expected trend of the transfer function for a RC low pass filter


void myfit(){




   gStyle->SetOptFit(11111);
   TCanvas *c1 = new TCanvas("c1","Data Analysis",200,10,700,500);





   TGraph* gr = new TGraph(sizeof(nu)/sizeof(double),nu,A);

   TF1 *funz =new TF1("funz","1./sqrt(1+(x/[0])**2)",1,1e4);    //hypotetical transfer function for a RC low pass filter

   funz->SetParameter(0,80);
   gPad->SetLogx();	

	

	
   gr->GetXaxis()->SetTitle("Frequency [kHz]");   		
   gr->GetYaxis()->SetTitle("Transfer Funcion");           
   gr->GetYaxis()->SetRange(0,1);
   gr->GetXaxis()->SetRange(1,1e4);
   
gr->SetTitle("Transfer function development depending on the frequency");

 gr->Fit(funz);
   gr->Draw("A*");


}
