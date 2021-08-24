// Macro used for plotting resonance data from two data files, can add more just need to duplicate sections of the code.
// The data is combined from RIPL-3 and another unnamed data file which does not have an author but was provided by my supervisor.

void plot(const char* file1, const char* file2){
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
c1->SetGrid();
TMultiGraph *mg = new TMultiGraph("mg","Mass Number (A) versus Average Resonance Spacing D_{0} (keV) for neutron capture");

TGraphErrors *gr = new TGraphErrors(file1, "%*s %*s %lg %*s %*s %lg %lg %*s %*s %*s %*s %*s");
TGraph *gr1 = new TGraph(file2, "%*s %lg %lg");
// TGraph *gr2 = new TGraph();
// gr2->SetPoint(0, 50., 3.80);


gr->SetMarkerColor(2);
gr->SetMarkerStyle(20);
gr->SetMarkerSize(0.7);

gr1->SetMarkerColor(4);
gr1->SetMarkerStyle(21);
gr1->SetMarkerSize(0.7);

// gr2->SetMarkerColor(6);
// gr2->SetMarkerStyle(21);

 mg->Add(gr);
 mg->Add(gr1, "PL");
// mg->Add(gr2);

mg->GetXaxis()->SetRangeUser(44,92);
mg->GetYaxis()->SetRangeUser(-5,60);

mg->GetXaxis()->SetTitle("Mass Number (A)");
mg->GetYaxis()->SetTitle("Average Resonance Spacing D_{0} (keV)");


mg->Draw("AP");

// auto legend = new TLegend(0.8,0.8,0.9,0.9);
// legend->AddEntry(gr, "Sr","lp");
// legend->AddEntry(gr1,"Zr","lp");
// legend->AddEntry(gr2,"Y","p");
// legend->Draw();

gPad->Update();
gPad->Modified();
}