cout << "left char: " << leftside[leftSize-1][i] << endl;
            cout << "right char: " << rightside[0][i] << endl;
            cout << "left num is: " << orderArr[(122-(int)(leftside[leftSize-1][i])+1)%26] << endl;
            cout << "right num is: " << orderArr[(122-(int)(rightside[0][i])+1)%26] << endl << endl;