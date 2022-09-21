void plot(const char* file1, const char* file2, const char* file3){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 500,500,600,400);

TMultiGraph *mg = new TMultiGraph("mg","");

TGraphErrors *gr = new TGraphErrors(file1, "%lg %lg %lg");
// TGraph *grr = new TGraph(file1, "%lg %*s %*s %lg %*s %*s");
TGraphErrors *gr1 = new TGraphErrors(file2, "%*s %lg  %*s %*s %lg %lg %*s %*s");
// TGraphErrors *gr2 = new TGraphErrors(file3, "%*s %lg %lg %lg");
// TGraph *gr3 = new TGraph(file4, "%lg %*s %*s %lg %*s %*s");

// Options

gr->SetMarkerColor(1);
gr->SetMarkerStyle(21);
gr->SetMarkerSize(1);
gr->SetLineWidth(1);
gr->SetLineColor(1);

// grr->SetMarkerColor(4);
// grr->SetMarkerStyle(20);

gr1->SetMarkerColor(kRed);
gr1->SetMarkerStyle(26);
gr1->SetMarkerSize(1);


// gr2->SetMarkerColor(kMagenta-3);
// gr2->SetMarkerSize(1.5);
// gr2->SetMarkerStyle(22);

// gr3->SetMarkerColor(kGreen+3);
// gr3->SetMarkerSize(1.5);
// gr3->SetMarkerStyle(43); 

mg->Add(gr,"p");
// mg->Add(grr);
mg->Add(gr1,"p");
// mg->Add(gr2,"p");
// mg->Add(gr3,"p");

mg->GetXaxis()->SetRangeUser(65,110);
mg->GetYaxis()->SetRangeUser(-1,35);


mg->GetXaxis()->SetTitle("Nuclear Mass (a.m.u)");
mg->GetYaxis()->SetTitle("D_{0} (keV)");

//Draw

mg->Draw("APL");

auto legend = new TLegend(0.15,0.7,0.3,0.85);
legend->SetBorderSize(0);
legend->AddEntry(gr, "Experimental D_{0}","lp");
// legend->AddEntry(grr,"CTM + FGM","lp");
legend->AddEntry(gr1,"RFR Test Set","lp");
// legend->AddEntry(gr2,"Symmetric","lp");
// legend->AddEntry(gr3,"Symmetric","lp");
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