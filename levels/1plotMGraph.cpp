void plot(const char* file1, const char* file2, const char* file3,const char* file4){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","Energy (MeV) versus No. of nuclear level density states");

TGraph *gr = new TGraph(file1, "%lg %*s %lg %*s %*s %*s");
TGraph *grr = new TGraph(file1, "%lg %*s %*s %lg %*s %*s");
TGraph *gr1 = new TGraph(file2, "%lg %*s %*s %lg %*s %*s");
TGraph *gr2 = new TGraph(file3, "%lg %*s %*s %lg %*s %*s");
TGraph *gr3 = new TGraph(file4, "%lg %*s %*s %lg %*s %*s");

// Options

gr->SetMarkerColor(1);
gr->SetMarkerStyle(21);
gr->SetLineColor(1);

grr->SetMarkerColor(4);
grr->SetMarkerStyle(20);

gr1->SetMarkerColor(5);
gr1->SetMarkerStyle(20);

gr2->SetMarkerColor(6);
gr2->SetMarkerStyle(20);

gr3->SetMarkerColor(7);
gr3->SetMarkerStyle(20); 

mg->Add(gr);
mg->Add(grr);
mg->Add(gr1);
mg->Add(gr2);
mg->Add(gr3);

mg->GetXaxis()->SetRangeUser(0,5);
mg->GetYaxis()->SetRangeUser(1,200);


mg->GetXaxis()->SetTitle("Energy (MeV)");
mg->GetYaxis()->SetTitle("No. of nuclear level density states");

//Draw

mg->Draw("APL");

auto legend = new TLegend(0.8,0.8,0.9,0.9);
legend->AddEntry(gr, "Discrete States","lp");
legend->AddEntry(grr,"FGM+CTM","lp");
legend->AddEntry(gr1,"BSFGM","lp");
legend->AddEntry(gr2,"HFB + Skyrme","lp");
legend->AddEntry(gr3,"HFB + Gogny","lp");
legend->Draw();

gPad->Modified();
gPad->Update();

}