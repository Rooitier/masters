// Macro used for plotting resonance data from two data files, can add more just need to duplicate sections of the code.
// The data is combined from RIPL-3 and another unnamed data file which does not have an author but was provided by my supervisor.

void plot(const char* file1){
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
c1->SetGrid();
TMultiGraph *mg = new TMultiGraph();

TGraphErrors *gr = new TGraphErrors(file1, "%*s %*s %lg %*s %*s %*s %*s %*s %*s %lg %lg %*s");
// TGraphErrors *gr1 = new TGraphErrors(file2, "%lg %*s %*s %lg %lg");
// TGraph *gr2 = new TGraph();
// gr2->SetPoint(0, 50., 3.80);


gr->SetMarkerColor(2);
gr->SetMarkerStyle(20);
gr->SetMarkerSize(0.7);

gr->GetXaxis()->SetRangeUser(44,92);
// gr->GetYaxis()->SetRangeUser(-5,60);

// gr1->SetMarkerColor(2);
// gr1->SetMarkerStyle(21);

// gr2->SetMarkerColor(6);
// gr2->SetMarkerStyle(21);

// mg->Add(gr);
// mg->Add(gr1);
// mg->Add(gr2);


gr->GetXaxis()->SetTitle("Mass number (A)");
gr->GetYaxis()->SetTitle("Average Radiative Width #LT #Gamma #GT (MeV)");
gr->SetTitle("Mass Number (A) versus Average Radiative Width #LT #Gamma #GT (MeV) for neutron capture");


gr->Draw("AP");

// auto legend = new TLegend(0.8,0.8,0.9,0.9);
// legend->AddEntry(gr, "Sr","lp");
// legend->AddEntry(gr1,"Zr","lp");
// legend->AddEntry(gr2,"Y","p");
// legend->Draw();

gPad->Update();
gPad->Modified();
}