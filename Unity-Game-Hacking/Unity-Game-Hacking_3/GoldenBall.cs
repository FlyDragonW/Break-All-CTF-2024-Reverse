using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoldenBall : MonoBehaviour
{
    public int Number;
    public GameManager manager;
    private void OnCollisionEnter(Collision collision)
    {
        manager.OnHitBall(Number);
        Destroy(this.gameObject);
    }
}
