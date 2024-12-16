using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public int password = 0;
    int hittimes = 0;
    public GameObject goldenBallPrefab;
    public GameObject flag;
    void Start()
    {
        for(int i = 0; i < 10; i++)
        {
            GameObject Ball = Instantiate(goldenBallPrefab, transform);
            Ball.transform.position = new Vector3(3f * i, 1, 8);
            GoldenBall BallScript = Ball.GetComponent<GoldenBall>();
            BallScript.manager = this.GetComponent<GameManager>();
            BallScript.Number = i;
        }
    }

    public void OnHitBall(int number)
    {
        if(hittimes % 2 == 0)
        {
            password += number;
        }
        else if(hittimes % 3 == 0)
        {
            password *= number;
        }
        else if(hittimes % 5 == 0)
        {
            password -= number;
        }
        else
        {
            password -= number;
            password *= 2;
        }
        if (password == 3000)
        {
            flag.SetActive(true);
        }
        hittimes++;
    }
}
