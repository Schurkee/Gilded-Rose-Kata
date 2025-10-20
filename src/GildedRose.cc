#include "GildedRose.h"

#include <algorithm>
#include <iostream>
#include <__msvc_ostream.hpp>

using namespace std;

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    /*for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != "Sulfuras, Hand of Ragnaros")
                {
                    items[i].quality -= 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality += 1;

                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality += 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality += 1;
                        }
                    }
                }
            }
        }

        if (items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            items[i].sellIn -= 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != "Aged Brie")
            {
                if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != "Sulfuras, Hand of Ragnaros")
                        {
                            items[i].quality -= 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = 0;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality += 1;
                }
            }
        }
    }*/

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == "Sulfuras, Hand of Ragnaros")
        {
            continue;
        }
        
        if (items[i].name == "Aged Brie")
        {
            items[i].quality += 2;
        }
        else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].sellIn <= 5)
            {
                items[i].quality += 3;
            }
            if (items[i].sellIn <= 10)
            {
                items[i].quality += 2;
            }
            if (items[i].sellIn <= 0)
            {
                items[i].quality = 0;
            }
        }
        else if (items[i].name == "Conjured Mana Cake")
        {
            items[i].quality -= 2;
        }
        else
        {
            items[i].quality -= 1;
        }

        items[i].sellIn -= 1;

        items[i].quality = std::max(items[i].quality, 0);

        items[i].quality = std::min(items[i].quality, 50);
    }
}
