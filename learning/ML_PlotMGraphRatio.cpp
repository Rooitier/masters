void ratioplot(const char* file1, const char* file2, const char* file3){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 500,500,600,400);

TMultiGraph *mg = new TMultiGraph("mg","");

// TGraphErrors *gr = new TGraphErrors(file1, "%lg %lg %lg");
// TGraph *grr = new TGraph(file1, "%*s %lg %*s %*s %lg %*s %*s");
TGraphErrors *gr1 = new TGraphErrors(file1, "%*s %lg %*s %*s %*s %*s %lg %lg");
TGraphErrors  *gr2 = new TGraphErrors(file2, "%*s %lg %*s %*s %*s %*s %lg %lg");
TGraphErrors  *gr3 = new TGraphErrors(file3, "%*s %lg %*s %*s %*s %*s %lg %lg");

// Options

// gr->SetMarkerColor(1);
// gr->SetMarkerStyle(21);
// gr->SetMarkerSize(0.7);
// gr->SetLineWidth(1);
// gr->SetLineColor(1);

// grr->SetMarkerColor(kBlue);
// grr->SetMarkerStyle(24);

gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(24);
gr1->SetMarkerSize(1.3);


gr2->SetMarkerColor(kRed);
gr2->SetMarkerSize(1);
gr2->SetMarkerStyle(22);

gr3->SetMarkerColor(kGreen+3);
gr3->SetMarkerSize(1.5);
gr3->SetMarkerStyle(33); 

// mg->Add(gr,"p");
// mg->Add(grr,"p");
mg->Add(gr1,"p");
mg->Add(gr2,"p");
mg->Add(gr3,"p");

// mg->GetXaxis()->SetRangeUser(35,260);
// mg->GetYaxis()->SetRangeUser(-1000,1000);


mg->GetXaxis()->SetTitle("Nuclear Mass (a.m.u)");
mg->GetYaxis()->SetTitle("D_{0}_{th}  / D_{0}_{exp} (a.u.)");
mg->GetYaxis()->SetMaxDigits(4);
mg->GetYaxis()->SetNdivisions(50510);

//Draw

mg->Draw("APL");



auto legend = new TLegend(0.15,0.7,0.3,0.85);
legend->SetBorderSize(0);
// legend->AddEntry(gr, "Experimental D_{0}","lp");
// legend->AddEntry(grr,"CTM + FGM","p");
legend->AddEntry(gr1,"No Parity","lp");
legend->AddEntry(gr2,"Asymmetric","lp");
legend->AddEntry(gr3,"Symmetric","lp");
legend->Draw();


TStyle *st1 = new TStyle("st1","my style");


st1->SetLabelFont(132,"xyz");
st1->SetTitleFont(132,"xyz");
st1->SetLegendFont(132);
st1->SetPalette(1,0); // avoid horrible default color scheme 
st1->SetOptStat(0); 
st1->SetOptTitle(0); 
st1->SetOptDate(0); 
st1->SetLabelSize(0.03,"xyz"); // size of axis value font 
st1->SetTitleSize(0.035,"xyz"); // size of axis title font 
st1->SetTitleOffset(1.2,"y");

// default canvas options 
st1->SetCanvasDefW(500); 
st1->SetCanvasDefH(500); 

st1->SetCanvasColor(0);  // canvas... 
st1->SetCanvasBorderMode(0); 
st1->SetCanvasBorderSize(0); 
st1->SetPadBottomMargin(0.1); //margins... 
st1->SetPadTopMargin(0.1); 
st1->SetPadLeftMargin(0.1); 
st1->SetPadRightMargin(0.1); 
st1->SetPadGridX(0); // grids, tickmarks 
st1->SetPadGridY(0); 
st1->SetPadTickX(1); 
st1->SetPadTickY(1); 
st1->SetFrameBorderMode(0); 
st1->SetPaperSize(20,24);
st1->cd(); 

gROOT->SetStyle("st1");
gPad->Modified();
gPad->Update();

}