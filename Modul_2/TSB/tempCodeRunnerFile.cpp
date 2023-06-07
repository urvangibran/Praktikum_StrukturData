for(int i=0; i<n; i++)
    {
        cout << temp->key << " "<< temp->stamina <<  " " << temp->parent->key << " " << temp->parent->stamina << endl;
        temp = temp->left;
    }